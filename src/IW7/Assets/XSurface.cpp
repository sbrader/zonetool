#include "stdafx.hpp"

namespace ZoneTool::IW7
{
	void dump_subdiv(XSurface* surf, assetmanager::dumper& dumper)
	{
		if (surf->subdiv)
		{
			dumper.dump_single(surf->subdiv);

			if (surf->subdiv->levels)
			{
				dumper.dump_array(surf->subdiv->levels, surf->subdivLevelCount);
				auto* levels = surf->subdiv->levels;
				auto level_count = surf->subdivLevelCount;
				for (unsigned char level_index = 0; level_index < level_count; level_index++)
				{
					auto* level = &levels[level_index];

					dumper.dump_raw(level->rigidVertLists, 16 * surf->rigidVertListCount);
					dumper.dump_raw(level->faceIndices, 12 * level->faceCount);
					dumper.dump_raw(level->regularPatchIndices, 32 * level->regularPatchCount);
					dumper.dump_raw(level->regularPatchFlags, 4 * level->regularPatchCount);
					dumper.dump_raw(level->facePoints, level->facePointBufferSize & 0xFFFFFFFC);
					dumper.dump_raw(level->edgePoints, 8 * level->edgePointCount);
					dumper.dump_raw(level->vertexPoints, level->vertexPointBufferSize & 0xFFFFFFFC);
					dumper.dump_raw(level->normals, level->normalBufferSize & 0xFFFFFFFC);
					dumper.dump_raw(level->transitionPoints, 4 * level->transitionPointCount);
					dumper.dump_raw(level->regularPatchCones, 32 * level->regularPatchCount);
				}
			}
		}
	}

	void dump_shprobesimplexdata(XSurface* surf, assetmanager::dumper& dumper)
	{
		if ((surf->flags & 0x500) == 0x500)
		{
			dumper.dump_array(surf->shProbeSimplexVertData.data0, surf->vertCount);
		}
		else if ((surf->flags & 0x100) != 0)
		{
			dumper.dump_array(surf->shProbeSimplexVertData.data1, surf->vertCount);
		}
		else if ((surf->flags & 0x400) != 0)
		{
			dumper.dump_array(surf->shProbeSimplexVertData.data2, surf->vertCount);
		}
	}

	void IXSurface::dump(XModelSurfs* asset)
	{
		const auto path = "xsurface\\"s + asset->name + ".xsb";

		assetmanager::dumper dump;
		if (!dump.open(path))
		{
			return;
		}

		dump.dump_single(asset);
		dump.dump_string(asset->name);

		dump.dump_array(asset->surfs, asset->numsurfs);
		for (unsigned short i = 0; i < asset->numsurfs; i++)
		{
			if ((asset->surfs[i].flags & 8) != 0)
			{
				dump.dump_array(asset->surfs[i].verts0.packedMotionVerts0, asset->surfs[i].vertCount);
			}
			else
			{
				dump.dump_array(asset->surfs[i].verts0.packedVerts0, asset->surfs[i].vertCount);
			}

			dump.dump_array(asset->surfs[i].triIndices, asset->surfs[i].triCount);

			dump.dump_array(asset->surfs[i].rigidVertLists, asset->surfs[i].rigidVertListCount);
			for (unsigned char vert = 0; vert < asset->surfs[i].rigidVertListCount; vert++)
			{
				if (asset->surfs[i].rigidVertLists)
				{
					if (asset->surfs[i].rigidVertLists[vert].collisionTree)
					{
						dump.dump_single(asset->surfs[i].rigidVertLists[vert].collisionTree);

						if (asset->surfs[i].rigidVertLists[vert].collisionTree->leafs)
						{
							dump.dump_array(asset->surfs[i].rigidVertLists[vert].collisionTree->leafs,
								asset->surfs[i].rigidVertLists[vert].collisionTree->leafCount);
						}
						if (asset->surfs[i].rigidVertLists[vert].collisionTree->nodes)
						{
							dump.dump_array(asset->surfs[i].rigidVertLists[vert].collisionTree->nodes,
								asset->surfs[i].rigidVertLists[vert].collisionTree->nodeCount);
						}
					}
				}
			}

			dump.dump_raw(asset->surfs[i].blendVerts, asset->surfs[i].blendVertSize & 0xFFFFFFFE);

			dump.dump_raw(asset->surfs[i].lmapUnwrap, 8 * asset->surfs[i].vertCount);

			dump.dump_raw(asset->surfs[i].tensionData, 4 * (asset->surfs[i].blendVertCounts[0]
				+ asset->surfs[i].blendVertCounts[1]
				+ asset->surfs[i].blendVertCounts[2]
				+ asset->surfs[i].blendVertCounts[3]
				+ asset->surfs[i].blendVertCounts[4]
				+ asset->surfs[i].blendVertCounts[5]
				+ asset->surfs[i].blendVertCounts[6]
				+ asset->surfs[i].blendVertCounts[7]));
			dump.dump_raw(asset->surfs[i].tensionAccumTable, 32 * asset->surfs[i].vertCount);

			dump_subdiv(&asset->surfs[i], dump);
			dump_shprobesimplexdata(&asset->surfs[i], dump);
		}

		dump.close();
	}
}