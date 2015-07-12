#pragma once

#include <string>
#include <Enseed/Reflect/API/Class.h>

namespace season
{
	namespace parsing
	{
		template<class TREE>
		struct ConvertComplexType<TREE, std::string>
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

}