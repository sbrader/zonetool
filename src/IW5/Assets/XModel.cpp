#include "stdafx.hpp"

#include "Dumper/H1/Assets/XModel.hpp"
#include "Dumper/IW6/Assets/XModel.hpp"

namespace ZoneTool::IW5
{
	void IXModel::dump(XModel* asset, const std::function<const char* (uint16_t)>& convertToString)
	{
		if (zonetool::dumping_target == zonetool::dump_target::h1)
		{
			return H1Dumper::dump(asset, convertToString);
		}
		else if (zonetool::dumping_target == zonetool::dump_target::iw6)
		{
			return IW6Dumper::dump(asset, convertToString);
		}
	}
}