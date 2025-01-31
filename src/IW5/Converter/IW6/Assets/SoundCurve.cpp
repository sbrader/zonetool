#include "stdafx.hpp"
#include "../Include.hpp"

#include "SoundCurve.hpp"

namespace ZoneTool::IW5
{
	namespace IW6Converter
	{
		IW6::SndCurve* GenerateIW6SoundCurve(SndCurve* asset, allocator& mem)
		{
			auto* iw6_asset = mem.allocate<IW6::SndCurve>();

			iw6_asset->name = asset->filename;
			iw6_asset->knotCount = asset->knotCount;
			memcpy(iw6_asset->knots, asset->knots, sizeof(IW5::vec2_t[16]));

			return iw6_asset;
		}

		IW6::SndCurve* convert(SndCurve* asset, allocator& allocator)
		{
			// generate IW6 asset
			return GenerateIW6SoundCurve(asset, allocator);
		}
	}
}