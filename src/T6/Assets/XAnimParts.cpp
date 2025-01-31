// ======================= ZoneTool =======================
// zonetool, a fastfile linker for various
// Call of Duty titles. 
//
// Project: https://github.com/ZoneTool/zonetool
// Author: RektInator (https://github.com/RektInator)
// License: GNU GPL v3.0
// ========================================================
#include "stdafx.hpp"

namespace ZoneTool
{
	namespace T6
	{
		//XAnimParts* IXAnimParts::parse_xae2(const std::string& name, ZoneMemory* mem, const std::function<std::uint16_t(const std::string&)>& allocString)
		//{
		//	const auto path = "XAnim\\"s + name + ".xae2";

		//	AssetReader reader(mem);
		//	if (!reader.open(path))
		//	{
		//		return nullptr;
		//	}

		//	ZONETOOL_INFO("Parsing XAE2 file \"%s\"...", name.c_str());
		//	ZONETOOL_WARNING("You are using an outdated animation! Redump the animations using a newer version of zonetool!");

		//	auto* asset = reader.read_single<XAnimParts>();
		//	asset->name = reader.read_string();

		//	asset->tagnames = mem->Alloc<unsigned short>(asset->boneCount[9]);
		//	for (auto bone = 0; bone < asset->boneCount[9]; bone++)
		//	{
		//		asset->tagnames[bone] = allocString(reader.read_string());
		//	}

		//	if (asset->dataByte)
		//	{
		//		asset->dataByte = reader.read_array<char>();
		//	}
		//	if (asset->dataShort)
		//	{
		//		asset->dataShort = reader.read_array<short>();
		//	}
		//	if (asset->dataInt)
		//	{
		//		asset->dataInt = reader.read_array<int>();
		//	}
		//	if (asset->randomDataShort)
		//	{
		//		asset->randomDataShort = reader.read_array<short>();
		//	}
		//	if (asset->randomDataByte)
		//	{
		//		asset->randomDataByte = reader.read_array<char>();
		//	}
		//	if (asset->randomDataInt)
		//	{
		//		asset->randomDataInt = reader.read_array<int>();
		//	}
		//	if (asset->indices.data)
		//	{
		//		if (asset->framecount > 255)
		//		{
		//			asset->indices._2 = reader.read_array<std::uint16_t>();
		//		}
		//		else
		//		{
		//			asset->indices._1 = reader.read_array<char>();
		//		}
		//	}

		//	if (asset->notetracks)
		//	{
		//		asset->notetracks = reader.read_array<XAnimNotifyInfo>();

		//		for (auto i = 0; i < asset->notetrackCount; i++)
		//		{
		//			asset->notetracks[i].name = allocString(reader.read_string());
		//		}
		//	}

		//	if (asset->delta)
		//	{
		//		asset->delta = nullptr;
		//	}

		//	reader.close();

		//	return asset;
		//}

		//XAnimParts* IXAnimParts::parse_xae3(const std::string& name, ZoneMemory* mem, const std::function<std::uint16_t(const std::string&)>& allocString)
		//{
		//	const auto path = "XAnim\\"s + name + ".xae3";

		//	AssetReader reader(mem);
		//	if (!reader.open(path))
		//	{
		//		return nullptr;
		//	}

		//	ZONETOOL_INFO("Parsing XAE3 file \"%s\"...", name.c_str());

		//	auto* asset = reader.read_single<XAnimParts>();
		//	asset->name = reader.read_string();

		//	asset->tagnames = mem->Alloc<unsigned short>(asset->boneCount[9]);
		//	for (auto bone = 0; bone < asset->boneCount[9]; bone++)
		//	{
		//		asset->tagnames[bone] = allocString(reader.read_string());
		//	}

		//	if (asset->dataByte)
		//	{
		//		asset->dataByte = reader.read_array<char>();
		//	}
		//	if (asset->dataShort)
		//	{
		//		asset->dataShort = reader.read_array<short>();
		//	}
		//	if (asset->dataInt)
		//	{
		//		asset->dataInt = reader.read_array<int>();
		//	}
		//	if (asset->randomDataShort)
		//	{
		//		asset->randomDataShort = reader.read_array<short>();
		//	}
		//	if (asset->randomDataByte)
		//	{
		//		asset->randomDataByte = reader.read_array<char>();
		//	}
		//	if (asset->randomDataInt)
		//	{
		//		asset->randomDataInt = reader.read_array<int>();
		//	}
		//	if (asset->indices.data)
		//	{
		//		if (asset->framecount > 255)
		//		{
		//			asset->indices._2 = reader.read_array<std::uint16_t>();
		//		}
		//		else
		//		{
		//			asset->indices._1 = reader.read_array<char>();
		//		}
		//	}

		//	if (asset->notetracks)
		//	{
		//		asset->notetracks = reader.read_array<XAnimNotifyInfo>();

		//		for (auto i = 0; i < asset->notetrackCount; i++)
		//		{
		//			asset->notetracks[i].name = allocString(reader.read_string());
		//		}
		//	}

		//	if (asset->delta)
		//	{
		//		asset->delta = reader.read_single<XAnimDeltaPart>();

		//		if (asset->delta->trans)
		//		{
		//			asset->delta->trans = reader.read_raw<XAnimPartTrans>();

		//			if (asset->delta->trans->size)
		//			{
		//				if (asset->delta->trans->u.frames.frames._1)
		//				{
		//					if (asset->delta->trans->smallTrans)
		//					{
		//						asset->delta->trans->u.frames.frames._1 = reader.read_raw<char[3]>();
		//					}
		//					else
		//					{
		//						asset->delta->trans->u.frames.frames._2 = reader.read_raw<unsigned short[3]>();
		//					}
		//				}
		//			}
		//		}

		//		if (asset->delta->quat2)
		//		{
		//			asset->delta->quat2 = reader.read_raw<XAnimDeltaPartQuat2>();

		//			if (asset->delta->quat2->size && asset->delta->quat2->u.frames.frames)
		//			{
		//				asset->delta->quat2->u.frames.frames = reader.read_raw<short[2]>();
		//			}
		//		}
		//		
		//		if (asset->delta->quat)
		//		{
		//			asset->delta->quat = reader.read_raw<XAnimDeltaPartQuat>();

		//			if (asset->delta->quat->size && asset->delta->quat->u.frames.frames)
		//			{
		//				asset->delta->quat->u.frames.frames = reader.read_raw<short[4]>();
		//			}
		//		}
		//	}

		//	reader.close();

		//	return asset;
		//}

		//XAnimParts* IXAnimParts::parse(const std::string& name, ZoneMemory* mem, const std::function<std::uint16_t(const std::string&)>& allocString)
		//{
		//	auto* parsed = IXAnimParts::parse_xae3(name, mem, allocString);

		//	if (!parsed)
		//	{
		//		parsed = IXAnimParts::parse_xae2(name, mem, allocString);
		//	}

		//	return parsed;
		//}

		//void IXAnimParts::init(const std::string& name, ZoneMemory* mem)
		//{
		//	this->name_ = name;
		//	this->asset_ = IXAnimParts::parse(name, mem);

		//	if (!this->asset_)
		//	{
		//		this->asset_ = DB_FindXAssetHeader(this->type(), this->name().data(), 1).xanimparts;
		//	}
		//}

		//void IXAnimParts::prepare(ZoneBuffer* buf, ZoneMemory* mem)
		//{
		//	// fixup scriptstrings
		//	auto xanim = mem->Alloc<XAnimParts>();
		//	memcpy(xanim, this->asset_, sizeof XAnimParts);

		//	// allocate tagnames
		//	if (this->asset_->tagnames)
		//	{
		//		xanim->tagnames = mem->Alloc<unsigned short>(xanim->boneCount[9]);
		//		memcpy(xanim->tagnames, this->asset_->tagnames, sizeof(unsigned short) * xanim->boneCount[9]);

		//		for (int i = 0; i < xanim->boneCount[9]; i++)
		//		{
		//			if (xanim->tagnames[i])
		//			{
		//				std::string bone = SL_ConvertToString(this->asset_->tagnames[i]);
		//				xanim->tagnames[i] = buf->write_scriptstring(bone);
		//			}
		//		}
		//	}

		//	// allocate notetracks
		//	xanim->notetracks = mem->Alloc<XAnimNotifyInfo>(xanim->notetrackCount);
		//	memcpy(xanim->notetracks, this->asset_->notetracks, sizeof XAnimNotifyInfo * xanim->notetrackCount);

		//	// touch XAnimNotifyInfo, realloc tagnames
		//	for (int i = 0; i < xanim->notetrackCount; i++)
		//	{
		//		std::string bone = SL_ConvertToString(this->asset_->notetracks[i].name);
		//		xanim->notetracks[i].name = buf->write_scriptstring(bone);
		//	}

		//	this->asset_ = xanim;
		//}

		//void IXAnimParts::load_depending(IZone* zone)
		//{
		//}

		//std::string IXAnimParts::name()
		//{
		//	return this->name_;
		//}

		//std::int32_t IXAnimParts::type()
		//{
		//	return xanim;
		//}

		//void IXAnimParts::write(IZone* zone, ZoneBuffer* buf)
		//{
		//	auto* data = this->asset_;
		//	auto* dest = buf->write(data);

		//	buf->push_stream(3);
		//	START_LOG_STREAM;

		//	dest->name = buf->write_str(this->name());

		//	if (data->tagnames) // tagnames
		//	{
		//		buf->align(1);
		//		buf->write_stream(data->tagnames, sizeof(short), data->boneCount[9]);
		//		dest->tagnames = reinterpret_cast<unsigned short*>(-1);
		//	}
		//	if (data->notetracks) // notetracks
		//	{
		//		buf->align(3);
		//		buf->write_stream(data->notetracks, sizeof(XAnimNotifyInfo), data->notetrackCount);
		//		dest->tagnames = reinterpret_cast<unsigned short*>(-1);
		//	}

		//	if (data->delta) // XAnimDeltaParts
		//	{
		//		buf->align(3);
		//		auto* partdata = data->delta;
		//		auto* partdest = reinterpret_cast<XAnimDeltaPart*>(buf->at());
		//		buf->write_stream(partdata, sizeof(XAnimDeltaPart), 1);
		//		
		//		if (partdata->trans)
		//		{
		//			buf->align(3);
		//			buf->write_stream(partdata->trans, 4, 1); // not full struct
		//			if (partdata->trans->size)
		//			{
		//				buf->write_stream(&partdata->trans->u, 0x1C, 1); // not full struct
		//				if (data->framecount > 0x100)
		//					buf->write_stream(&partdata->trans->u.frames.indices,
		//						sizeof(short), partdata->trans->size + 1);
		//				else
		//					buf->write_stream(&partdata->trans->u.frames.indices, sizeof(char),
		//						partdata->trans->size + 1);

		//				if (partdata->trans->u.frames.frames._1)
		//				{
		//					if (partdata->trans->smallTrans)
		//					{
		//						buf->align(0);
		//						buf->write_stream(partdata->trans->u.frames.frames._1, sizeof(char) * 3,
		//							partdata->trans->size + 1);
		//					}
		//					else
		//					{
		//						buf->align(3);
		//						buf->write_stream(partdata->trans->u.frames.frames._2, sizeof(short) * 3,
		//							partdata->trans->size + 1);
		//					}
		//				}
		//			}
		//			else buf->write_stream(partdata->trans->u.frame0, sizeof(float), 3);
		//			partdest->trans = reinterpret_cast<XAnimPartTrans*>(-1);
		//		}

		//		if (partdata->quat2)
		//		{
		//			buf->align(3);
		//			buf->write_stream(partdata->quat2, 4, 1); // not full struct
		//			
		//			if (partdata->quat2->size)
		//			{
		//				buf->write_stream(&partdata->quat2->u, 0x4, 1); // not full struct
		//				if (data->framecount > 255)
		//				{
		//					buf->write_stream(&partdata->quat2->u.frames.indices,
		//						sizeof(short), partdata->quat2->size + 1);
		//				}
		//				else
		//				{
		//					buf->write_stream(&partdata->quat2->u.frames.indices, sizeof(char),
		//						partdata->quat2->size + 1);
		//				}

		//				if (partdata->quat2->u.frames.frames)
		//				{
		//					buf->align(3);
		//					buf->write_stream(partdata->quat2->u.frames.frames, sizeof(short) * 2,
		//						partdata->quat2->size + 1);
		//				}
		//			}
		//			else 
		//			{
		//				buf->write_stream(partdata->quat2->u.frame0, sizeof(short) * 2, 1);
		//			}
		//			partdest->quat2 = reinterpret_cast<XAnimDeltaPartQuat2*>(-1);
		//		}

		//		if (partdata->quat)
		//		{
		//			buf->align(3);
		//			buf->write_stream(partdata->quat, 4, 1);
		//			
		//			if (partdata->quat->size)
		//			{
		//				buf->write_stream(&partdata->quat->u, 4, 1); // not full struct

		//				if (data->framecount > 255)
		//				{
		//					buf->write_stream(&partdata->quat->u.frames.indices,
		//						sizeof(short), partdata->quat->size + 1);
		//				}
		//				else
		//				{
		//					buf->write_stream(&partdata->quat->u.frames.indices, sizeof(char),
		//						partdata->quat->size + 1);
		//				}

		//				if (partdata->quat->u.frames.frames)
		//				{
		//					buf->align(3);
		//					buf->write_stream(partdata->quat->u.frames.frames, sizeof(short) * 4,
		//						partdata->quat->size + 1);
		//				}
		//			}
		//			else
		//			{
		//				buf->write_stream(partdata->quat->u.frame0, sizeof(short) * 4, 1);
		//			}

		//			partdest->quat = reinterpret_cast<XAnimDeltaPartQuat*>(-1);
		//		}

		//		dest->delta = reinterpret_cast<XAnimDeltaPart*>(-1);
		//	}

		//	if (data->dataByte) // dataByte
		//	{
		//		buf->align(0);
		//		buf->write_stream(data->dataByte, sizeof(char), data->dataByteCount);
		//		dest->dataByte = reinterpret_cast<char*>(-1);
		//	}
		//	if (data->dataShort) // dataShort
		//	{
		//		buf->align(1);
		//		buf->write_stream(data->dataShort, sizeof(short), data->dataShortCount);
		//		dest->dataShort = reinterpret_cast<short*>(-1);
		//	}
		//	if (data->dataInt) // dataInt
		//	{
		//		buf->align(3);
		//		buf->write_stream(data->dataInt, sizeof(int), data->dataIntCount);
		//		dest->dataInt = reinterpret_cast<int*>(-1);
		//	}
		//	if (data->randomDataShort) // randomDataShort
		//	{
		//		buf->align(1);
		//		buf->write_stream(data->randomDataShort, sizeof(short), data->randomDataShortCount);
		//		dest->randomDataShort = reinterpret_cast<short*>(-1);
		//	}
		//	if (data->randomDataByte) // randomDataByte
		//	{
		//		buf->align(0);
		//		buf->write_stream(data->randomDataByte, sizeof(char), data->randomDataByteCount);
		//		dest->randomDataByte = reinterpret_cast<char*>(-1);
		//	}
		//	if (data->randomDataInt) // randomDataInt
		//	{
		//		buf->align(3);
		//		buf->write_stream(data->randomDataInt, sizeof(int), data->randomDataIntCount);
		//		dest->randomDataInt = reinterpret_cast<int*>(-1);
		//	}

		//	// XAnim indice data
		//	if (data->indices.data)
		//	{
		//		if (data->framecount > 255)
		//		{
		//			buf->align(1);
		//			buf->write_stream(data->indices.data, data->indexcount * 2, 1);
		//		}
		//		else
		//		{
		//			buf->align(0);
		//			buf->write_stream(data->indices.data, data->indexcount, 1);
		//		}

		//		dest->indices.data = reinterpret_cast<void*>(-1);
		//	}

		//	END_LOG_STREAM;
		//	buf->pop_stream();
		//}

		void IXAnimParts::dump_xae3(XAnimParts* asset, const std::function<const char* (std::uint16_t)>& convertToString)
		{
			const auto path = "XAnim\\"s + asset->name + ".xae3";

			AssetDumper dump;
			if (!dump.open(path))
			{
				return;
			}

			dump.dump_single(asset);
			dump.dump_string(asset->name);

			for (auto bone = 0; bone < asset->boneCount[9]; bone++)
			{
				dump.dump_string(convertToString(asset->tagnames[bone]));
			}
			if (asset->dataByte)
			{
				dump.dump_array(asset->dataByte, asset->dataByteCount);
			}
			if (asset->dataShort)
			{
				dump.dump_array(asset->dataShort, asset->dataShortCount);
			}
			if (asset->dataInt)
			{
				dump.dump_array(asset->dataInt, asset->dataIntCount);
			}
			if (asset->randomDataShort)
			{
				dump.dump_array(asset->randomDataShort, asset->randomDataShortCount);
			}
			if (asset->randomDataByte)
			{
				dump.dump_array(asset->randomDataByte, asset->randomDataByteCount);
			}
			if (asset->randomDataInt)
			{
				dump.dump_array(asset->randomDataInt, asset->randomDataIntCount);
			}

			if (asset->indices.data)
			{
				if (asset->framecount > 255)
				{
					dump.dump_array(asset->indices._2, asset->indexcount);
				}
				else
				{
					dump.dump_array(asset->indices._1, asset->indexcount);
				}
			}

			if (asset->notetracks)
			{
				dump.dump_array(asset->notetracks, asset->notetrackCount);

				for (auto i = 0; i < asset->notetrackCount; i++)
				{
					dump.dump_string(convertToString(asset->notetracks[i].name));
				}
			}

			if (asset->delta)
			{
				dump.dump_single(asset->delta);

				if (asset->delta->trans)
				{
					auto extra_size = 0;

					if (asset->delta->trans->size)
					{
						if (asset->framecount > 255)
						{
							extra_size += (asset->delta->trans->size * 2) + 2;
						}
						else
						{
							extra_size += asset->delta->trans->size + 1;
						}
					}

					dump.dump_raw(asset->delta->trans, sizeof(XAnimPartTrans) + extra_size);

					if (asset->delta->trans->size)
					{
						if (asset->delta->trans->u.frames.frames._1)
						{
							if (asset->delta->trans->smallTrans)
							{
								dump.dump_raw(asset->delta->trans->u.frames.frames._1, (3 * asset->delta->trans->size) + 3);
							}
							else
							{
								dump.dump_raw(asset->delta->trans->u.frames.frames._2, (6 * asset->delta->trans->size) + 6);
							}
						}
					}
				}

				if (asset->delta->quat2)
				{
					auto extra_size = 0;
					
					if (asset->delta->quat2->size)
					{
						if (asset->framecount > 255)
						{
							extra_size += (asset->delta->quat2->size * 2) + 2;
						}
						else
						{
							extra_size += asset->delta->quat2->size + 1;
						}
					}
					else
					{
						// no extra size required, quat2 data fits inside the frame0 buffer
						extra_size += 0;
					}

					dump.dump_raw(asset->delta->quat2, sizeof(XAnimDeltaPartQuat2) + extra_size);

					if (asset->delta->quat2->size && asset->delta->quat2->u.frames.frames)
					{
						dump.dump_raw(asset->delta->quat2->u.frames.frames, (asset->delta->quat2->size * 4) + 4);
					}
				}

				if (asset->delta->quat)
				{
					auto extra_size = 0;

					if (asset->delta->quat->size)
					{
						if (asset->framecount > 255)
						{
							extra_size += (asset->delta->quat->size * 2) + 2;
						}
						else
						{
							extra_size += asset->delta->quat->size + 1;
						}
					}
					else
					{
						// quat data contains 4 extra bytes
						extra_size += 4;
					}

					dump.dump_raw(asset->delta->quat, sizeof(XAnimDeltaPartQuat) + extra_size);

					if (asset->delta->quat->size && asset->delta->quat->u.frames.frames)
					{
						dump.dump_raw(asset->delta->quat->u.frames.frames, (asset->delta->quat->size * 8) + 8);
					}
				}
			}

			dump.close();
		}

		void IXAnimParts::dump(XAnimParts* asset, const std::function<const char*(std::uint16_t)>& convertToString)
		{
			IXAnimParts::dump_xae3(asset, convertToString);
		}
	}
}
