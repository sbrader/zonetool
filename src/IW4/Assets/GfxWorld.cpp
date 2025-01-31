#include "stdafx.hpp"
#include "IW5/Assets/GfxWorld.hpp"

namespace ZoneTool
{
	namespace IW4
	{
		IW5::GfxWorld* generate_world(GfxWorld* asset, allocator& mem)
		{
			auto* iw5_asset = mem.allocate<IW5::GfxWorld>();
			memset(iw5_asset, 0, sizeof IW5::GfxWorld);

			// copy struct data
			memcpy(&iw5_asset->name, &asset->name, Difference(&iw5_asset->cells, &iw5_asset->name));

			// allocate cells
			iw5_asset->cells = mem.allocate<IW5::GfxCell>(iw5_asset->dpvsPlanes.cellCount);
			memset(iw5_asset->cells, 0, sizeof(IW5::GfxCell) * iw5_asset->dpvsPlanes.cellCount);

			// copy cell data
			for (int i = 0; i < iw5_asset->dpvsPlanes.cellCount; i++)
			{
				memcpy(&iw5_asset->cells[i], &asset->cells[i], sizeof GfxCell);
			}

			// copy draw data
			memcpy(&iw5_asset->draw.reflectionProbeCount, &asset->worldDraw.reflectionProbeCount, 16);
			memcpy(&iw5_asset->draw.lightmapCount, &asset->worldDraw.lightmapCount, 56);

			// copy remaining GfxWorld data
			memcpy(&iw5_asset->lightGrid, &asset->lightGrid,
				Difference(&iw5_asset->fogTypesAllowed + 1, &iw5_asset->lightGrid));

			// fix GfxDrawSurfs
			iw5_asset->dpvs.surfaceMaterials = mem.allocate<IW5::GfxDrawSurf>(iw5_asset->surfaceCount);
			memset(iw5_asset->dpvs.surfaceMaterials, 0, sizeof IW5::GfxDrawSurf * iw5_asset->surfaceCount);
			for (auto i = 0u; i < iw5_asset->surfaceCount; i++)
			{
				iw5_asset->dpvs.surfaceMaterials[i].fields.reflectionProbeIndex = asset->dpvs.surfaceMaterials[i].fields.reflectionProbeIndex;
				iw5_asset->dpvs.surfaceMaterials[i].fields.hasGfxEntIndex = asset->dpvs.surfaceMaterials[i].fields.hasGfxEntIndex;
				iw5_asset->dpvs.surfaceMaterials[i].fields.customIndex = asset->dpvs.surfaceMaterials[i].fields.customIndex;
				iw5_asset->dpvs.surfaceMaterials[i].fields.materialSortedIndex = asset->dpvs.surfaceMaterials[i].fields.materialSortedIndex;
				iw5_asset->dpvs.surfaceMaterials[i].fields.prepass = asset->dpvs.surfaceMaterials[i].fields.prepass;
				iw5_asset->dpvs.surfaceMaterials[i].fields.useHeroLighting = asset->dpvs.surfaceMaterials[i].fields.useHeroLighting;
				iw5_asset->dpvs.surfaceMaterials[i].fields.sceneLightIndex = asset->dpvs.surfaceMaterials[i].fields.sceneLightIndex;
				iw5_asset->dpvs.surfaceMaterials[i].fields.viewModelRender = 0;
				iw5_asset->dpvs.surfaceMaterials[i].fields.surfType = asset->dpvs.surfaceMaterials[i].fields.surfType;
				iw5_asset->dpvs.surfaceMaterials[i].fields.primarySortKey = asset->dpvs.surfaceMaterials[i].fields.primarySortKey;
				iw5_asset->dpvs.surfaceMaterials[i].fields.unused = asset->dpvs.surfaceMaterials[i].fields.unused;
			}

			return iw5_asset;
		}

		void IGfxWorld::dump(GfxWorld* asset)
		{
			allocator allocator;
			auto* iw5_asset = generate_world(asset, allocator);

			// dump asset
			IW5::IGfxWorld::dump(iw5_asset);
		}
	}
}