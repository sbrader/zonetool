// ======================= ZoneTool =======================
// zonetool, a fastfile linker for various
// Call of Duty titles. 
//
// Project: https://github.com/ZoneTool/zonetool
// Author: RektInator (https://github.com/RektInator)
// License: GNU GPL v3.0
// ========================================================
#pragma once

namespace ZoneTool
{
	namespace T6
	{
		class IPixelShader : public IAsset
		{
		private:
			std::string name_;
			MaterialPixelShader* asset_ = nullptr;

		public:
			static MaterialPixelShader* parse(const std::string& name, ZoneMemory* mem,
			                          bool preferLocal = false);

			void init(void* asset, ZoneMemory* mem) override;
			void init(const std::string& name, ZoneMemory* mem) override;
			void prepare(ZoneBuffer* buf, ZoneMemory* mem) override;
			void load_depending(IZone* zone) override;

			std::string name() override;
			std::int32_t type() override;
			void write(IZone* zone, ZoneBuffer* buffer) override;

			static void dump(MaterialPixelShader* asset);
		};
	}
}
