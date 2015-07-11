#pragma once

#include <string>
#include <Enseed/Reflect/API/Class.h>

namespace parsing
{
	template<class TREE, class T>
	struct TConvertNode<TREE, std::shared_ptr<T>, Kind::COMPLEX>
	{
		static void toDocument(const char *name, const std::shared_ptr<T> &objPtr, typename TREE::Document *document, typename TREE::Node *node)
		{
			if (objPtr)
			{
				ConvertNode<TREE, T>::toDocument(name, *objPtr, document, node);
			}
		}

		static void fromDocument(const typename TREE::Node &node, std::shared_ptr<T> *objPtr, typename TREE::Document *document)
		{
			if (!TREE::isEmpty(node))
			{
				objPtr->reset(new T);
				ConvertNode<TREE, T>::fromDocument(node, &(**objPtr), document);
			}
		}
	};
}

