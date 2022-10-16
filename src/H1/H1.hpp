// ======================= ZoneTool =======================
// zonetool, a fastfile linker for various
// Call of Duty titles. 
//
// Project: https://github.com/ZoneTool/zonetool
// Author: RektInator (https://github.com/RektInator)
// License: GNU GPL v3.0
// ========================================================
#pragma once

#include <ZoneUtils.hpp>

#include "Utils/IO/filesystem.hpp"
#include "Utils/IO/assetmanager.hpp"

#define JSON_DIAGNOSTICS 1
#include "json.hpp"
using json = nlohmann::json;
using ordered_json = nlohmann::ordered_json;

using namespace zonetool;

#include "Structs.hpp"

#include "Assets/ClipMap.hpp"
#include "Assets/ComWorld.hpp"
#include "Assets/FxEffectDef.hpp"
#include "Assets/FxWorld.hpp"
#include "Assets/GfxImage.hpp"
#include "Assets/GfxLightDef.hpp"
#include "Assets/GfxWorld.hpp"
#include "Assets/GlassWorld.hpp"
#include "Assets/MapEnts.hpp"
#include "Assets/PhysWorld.hpp"
#include "Assets/RawFile.hpp"
#include "Assets/XAnimParts.hpp"
#include "Assets/XModel.hpp"
#include "Assets/XSurface.hpp"

namespace ZoneTool
{
	namespace H1
	{
		
	}
}
