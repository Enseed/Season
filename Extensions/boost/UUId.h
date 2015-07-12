#pragma once

#include <string>
#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_io.hpp>
#include "LexicalCast.h"

namespace season
{
	namespace parsing
	{
		template<class TREE>
		struct ConvertComplexType<TREE, boost::uuids::uuid> : public ConvertNodeLexicalCast<TREE, boost::uuids::uuid>{};
	}
}

