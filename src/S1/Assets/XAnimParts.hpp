#pragma once

namespace ZoneTool::S1
{
	class IXAnimParts
	{
	public:
		static void dump(XAnimParts* asset, const std::function<const char* (std::uint16_t)>& SL_ConvertToString);
	};
}