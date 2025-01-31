IW4 = {}

function IW4:include()
    includedirs {
        path.join(ProjectFolder(), "IW4")
    }
end

function IW4:link()
    self:include()
	links {
		"IW4"
	}
end

function IW4:project()
    local folder = ProjectFolder();

    project "IW4"
        kind "StaticLib"
        language "C++"
        
        pchheader "stdafx.hpp"
        pchsource(path.join(folder, "IW4/stdafx.cpp"))

        files {
            path.join(folder, "IW4/**.h"),
            path.join(folder, "IW4/**.hpp"),
            path.join(folder, "IW4/**.cpp")
        }

        self:include()
        IW6:include()
        H1:include()
        ZoneUtils:include()

        zstd:include()
        zlib:include()

        X64:include()
end