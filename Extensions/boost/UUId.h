#pragma once

#include <string>
#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_io.hpp>
#include "LexicalCast.h"

namespace parsing
{
	template<class TREE>
	struct TConvertNode<TREE, boost::uuids::uuid, Kind::COMPLEX> : public ConvertNodeLexicalCast<TREE, boost::uuids::uuid> {};
}

