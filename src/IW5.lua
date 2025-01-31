IW5 = {}

function IW5:include()
    includedirs {
        path.join(ProjectFolder(), "IW5")
    }
end

function IW5:link()
    self:include()
	links {
		"IW5"
	}
end

function IW5:project()
    local folder = ProjectFolder();

    project "IW5"
        kind "StaticLib"
        language "C++"
        
        pchheader "stdafx.hpp"
        pchsource(path.join(folder, "IW5/stdafx.cpp"))

        files {
            path.join(folder, "IW5/**.h"),
            path.join(folder, "IW5/**.hpp"),
            path.join(folder, "IW5/**.cpp")
        }

        self:include()
        IW7:include()
        IW6:include()
        H1:include()
        ZoneUtils:include()

        zstd:include()
        zlib:include()

        gsc_tool:include()

        --directxtex:link()

        X64:include()
end