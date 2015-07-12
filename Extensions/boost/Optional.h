#pragma once

#include <string>
#include <boost/optional/optional.hpp>

namespace season
{
	namespace parsing
	{
		template<class TREE, class T>
		struct ConvertComplexType<TREE, boost::optional<T>>
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

}