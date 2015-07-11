#pragma once

#include <string>
#include <boost/lexical_cast.hpp>
#include <Enseed/Reflect/API/Class.h>

namespace parsing
{
	template<class TREE, class T>
	struct ConvertNodeLexicalCast
	{
		static void toDocument(const char *name, const T &obj, typename TREE::Document *document, typename TREE::Node *node)
		{
			std::string value = boost::lexical_cast<std::string>(obj);
			TREE::setString(node, name, value.c_str(), document);
		}

		static void fromDocument(const typename TREE::Node &node, T *obj, typename TREE::Document *document)
		{
			std::string strValue;
			*obj = boost::lexical_cast<T>(strValue);
		}
	};
}

