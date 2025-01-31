#include "stdafx.hpp"
#include "IW5/Assets/FxEffectDef.hpp"

namespace ZoneTool
{
	namespace IW4
	{
		void IFxEffectDef::dump(FxEffectDef* asset)
		{
			allocator allocator;

			// alloc comworld
			auto* iw5_fx = allocator.allocate<IW5::FxEffectDef>();
			memcpy(iw5_fx, asset, sizeof FxEffectDef);
			//memset(iw5_fx->pad, 0, sizeof iw5_fx->pad);

			// alloc elemdefs
			const auto elem_def_count = iw5_fx->elemDefCountEmission + iw5_fx->elemDefCountLooping + iw5_fx->elemDefCountOneShot;
			iw5_fx->elemDefs = allocator.allocate<IW5::FxElemDef>(elem_def_count);

			// transform elemdefs to iw5 format
			for (auto i = 0; i < elem_def_count; i++)
			{
				memcpy(&iw5_fx->elemDefs[i], &asset->elemDefs[i], sizeof(IW4::FxElemDef));
				iw5_fx->elemDefs[i].randomSeed = 0;
			}

			IW5::IFxEffectDef::dump(iw5_fx);
		}
	}
}