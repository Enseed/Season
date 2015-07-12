#pragma once

#include <string>
#include <Enseed/Reflect/API/Class.h>

namespace season
{
	namespace parsing
	{
		template<class TREE, class T>
		struct ConvertComplexType<TREE, std::vector<T>>
		{
			static void toDocument(const char *name, const std::vector<T> &vecObj, typename TREE::Document *document, typename TREE::Node *node)
			{
				TREE::Node vecNode;
				TREE::setArrayType(&vecNode);

				for (const T &obj : vecObj)
				{
					ConvertNode<TREE, T>::toDocument(nullptr, obj, document, &vecNode);
				}
				TREE::addNode(node, name, &vecNode, document);
			}

			static void fromDocument(const typename TREE::Node &node, std::vector<T> *vecObj, typename TREE::Document *document)
			{
				size_t size = TREE::getSize(node);
				vecObj->resize(size);
				typename TREE::ConstArrayIterator nodeIter = TREE::arrayBegin(node);
				for (std::vector<T>::iterator vecIter = vecObj->begin(); vecIter != vecObj->end(); ++nodeIter, ++vecIter)
				{
					ConvertNode<TREE, T>::fromDocument(TREE::getIterValue(nodeIter), &*vecIter, document);
				};
			}
		};
	}
}

