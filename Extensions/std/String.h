#pragma once

#include <string>
#include <Enseed/Reflect/API/Class.h>

namespace parsing
{
	template<class TREE>
	struct TConvertNode<TREE, std::string, Kind::COMPLEX>
	{
		static void toDocument(const char *name, const std::string &obj, typename TREE::Document *document, typename TREE::Node *node)
		{
			TREE::setStringRef(node, name, obj.c_str(), document);
		}

		static void fromDocument(const typename TREE::Node &node, std::string *obj, typename TREE::Document *document)
		{
			TREE::getString(node, obj, document);
		}
	};
}

