#pragma once

#include <string>
#include <memory>

namespace season
{
	namespace parsing
	{
		template<class TREE, class T>
		struct ConvertComplexType<TREE, std::unique_ptr<T>>
		{
			static void toDocument(const char *name, const std::unique_ptr<T> &objPtr, typename TREE::Document *document, typename TREE::Node *node)
			{
				if (objPtr)
				{
					ConvertNode<TREE, T>::toDocument(name, *objPtr, document, node);
				}
			}

			static void fromDocument(const typename TREE::Node &node, std::unique_ptr<T> *objPtr, typename TREE::Document *document)
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