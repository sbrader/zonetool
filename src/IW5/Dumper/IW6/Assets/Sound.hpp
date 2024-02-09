#pragma once

namespace ZoneTool::IW5
{
	namespace IW6Dumper
	{
		void dump(snd_alias_list_t* asset, const std::function<std::string(const char* filename)>& get_streamed_sound_data);
	}
}