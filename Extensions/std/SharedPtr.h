#pragma once

#include <string>
#include <Enseed/Reflect/API/Class.h>

namespace season
{
	namespace parsing
	{
		template<class TREE, class T>
		struct ConvertComplexType<TREE, std::shared_ptr<T>>
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
}