#include "stdafx.hpp"

#include "Dumper/H1/Assets/Material.hpp"
#include "Dumper/IW6/Assets/Material.hpp"

namespace ZoneTool::IW5
{
	void IMaterial::dump(Material* asset)
	{
		if (zonetool::dumping_target == zonetool::dump_target::h1)
		{
			return H1Dumper::dump(asset);
		}
		else if (zonetool::dumping_target == zonetool::dump_target::iw6)
		{
			return IW6Dumper::dump(asset);
		}
	}
}