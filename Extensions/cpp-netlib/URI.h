#pragma once

#include <string>
#include <cpp-netlib/uri/src/network/uri.hpp>

namespace season
{
	namespace parsing
	{
		template<class TREE>
		struct ConvertComplexType<TREE, network::uri> : public ConvertNodeLexicalCast<TREE, network::uri>{};
	}

}