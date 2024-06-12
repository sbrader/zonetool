#pragma once

namespace ZoneTool
{
	namespace H1
	{
		extern std::unordered_map<std::string, std::string> mapped_techsets;
	}

	namespace IW6
	{
		extern std::unordered_map<std::string, std::string> mapped_techsets;
	}

	namespace IW7
	{
		extern std::unordered_map<std::string, std::string> prefix_cache;

		extern std::unordered_map<std::string, std::string> mapped_techsets;
		extern std::string replace_material_prefix(const std::string& name, std::string technique = "");
		extern std::uint8_t convert_semantic(std::uint8_t from);
		extern std::uint8_t get_material_type_from_technique(std::string technique = "");
	}

	namespace IW5
	{
		class IMaterial
		{
		public:
			static void dump(Material* asset);
		};
	}
}