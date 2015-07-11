#pragma once

#include <string>
#include <Enseed/Reflect/API/Class.h>

namespace parsing
{
	template<class TREE, class T>
	struct TConvertNode<TREE, boost::optional<T>, Kind::COMPLEX>
	{
		static void toDocument(const char *name, const boost::optional<T> &optObj, typename TREE::Document *document, typename TREE::Node *node)
		{
			if (optObj)
			{
				ConvertNode<TREE, T>::toDocument(name, optObj.get(), document, node);
			}
		}

		static void fromDocument(const typename TREE::Node &node, boost::optional<T> *optObj, typename TREE::Document *document)
		{
			if (!TREE::isEmpty(node))
			{
				optObj->emplace();
				ConvertNode<TREE, T>::fromDocument(node, &optObj->get(), document);
			}
		}
	};
}

