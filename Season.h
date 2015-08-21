#pragma once

#include <string>
#include <map>
#include <Enseed/Reflect/API/Class.h>

#define ENSEED_SEASON_ENABLE_BOOST
#define ENSEED_SEASON_ENABLE_STD
#define ENSEED_SEASON_ENABLE_CPP_NETLIB
#define ENSEED_SEASON_ENABLE_ENSEED

namespace season
{

namespace parsing
{
	template<class TREE, class T>
	struct ConvertComplexType;

	template<class TREE, class T>
	struct ConvertSimpleType;

	template<class TREE, class T, int IS_FUNDAMENDAL = std::is_fundamental<T>::value>
	struct TConvertNode	{};

	template<class TREE, class T>
	struct TConvertNode<TREE, T, false> : public ConvertComplexType<TREE, T> {};

	template<class TREE, class T>
	struct TConvertNode<TREE, T, true> : public ConvertSimpleType<TREE, T> {};



	template<class TREE, class T, class NCNRT=std::remove_const<std::remove_reference<T>::type>::type>
	struct ConvertNode : public TConvertNode<TREE, NCNRT>
	{
		static void toDocument(const std::string &name, const T &obj, typename TREE::Document *document, typename TREE::Node *node)
		{
			TConvertNode::toDocument(name.c_str(), obj, document, node);
		}

		static void toDocument(const char *name, const T &obj, typename TREE::Document *document, typename TREE::Node *node)
		{
			TConvertNode::toDocument(name, obj, document, node);
		}

		static void fromDocument(const typename TREE::Node &node, T *obj, typename TREE::Document *document)
		{
			TConvertNode::fromDocument(node, obj, document);
		}
	};

	template<class TREE, class T>
	struct ConvertComplexType
	{
		template<class K, class V>
		static void toDocumentImpl(const char *name, const std::map<K,V> &map, typename TREE::Document *document, typename TREE::Node *node)
		{
			TREE::Node mapNode;
			TREE::setObjectType(&mapNode);

			for (const auto &keyValue : map)
			{
				const auto &key = keyValue.first;
				const auto &value = keyValue.second;
				ConvertNode<TREE, std::remove_reference<decltype(value)>::type>::toDocument(key, value, document, &mapNode);
			}

			TREE::addNode(node, name, &mapNode, document);
		}

		template<class V>
		static void toDocumentImpl(const char *name, const V &obj, typename TREE::Document *document, typename TREE::Node *node)
		{
			TREE::Node objNode;
			TREE::setObjectType(&objNode);
			reflect::Class<V>::visitFields([&obj, &document, &objNode](auto field) {
				const char *name = decltype(field)::name();
				const auto &value = decltype(field)::readRef(obj);
				ConvertNode<TREE, std::remove_reference<decltype(value)>::type>::toDocument(name, value, document, &objNode);
			});
			TREE::addNode(node, name, &objNode, document);
		}

		static void toDocument(const char *name, const T &obj, typename TREE::Document *document, typename TREE::Node *node)
		{
			// distinguish between types and map objects
			toDocumentImpl(name, obj, document, node);
		}

		template<class K, class V>
		static void fromDocumentImpl(const typename TREE::Node &node, std::map<K, V> *map, typename TREE::Document *document)
		{
			for (auto iter = TREE::attributeBegin(node); iter != TREE::attributeEnd(node); ++iter)
			{
				const char *name = TREE::getIterName(iter);
				V value;
				ConvertNode<TREE, V>::fromDocument(TREE::getIterValue(iter), &value, document);
				map->insert(std::make_pair(name, value));
			}
		}

		template<class V>
		static void fromDocumentImpl(const typename TREE::Node &node, V *obj, typename TREE::Document *document)
		{
			reflect::Class<V>::visitFields([&obj, &document, &node](auto field) {

				const char *name = decltype(field)::name();
				const TREE::Node *child = TREE::getNode(node, name);
				if (child != nullptr)
				{
					auto *value = decltype(field)::writePtr(obj);
					ConvertNode<TREE, std::remove_reference<decltype(*value)>::type>::fromDocument(*child, value, document);
				}
			});
		}

		static void fromDocument(const typename TREE::Node &node, T *obj, typename TREE::Document *document)
		{
			// distinguish between types and map objects
			fromDocumentImpl(node, obj, document);
		}
	};

	template<class TREE, class T>
	struct ConvertSimpleType
	{
		static void toDocument(const char *name, const T &obj, typename TREE::Document *document, typename TREE::Node *node)
		{
			TREE::setSimple(node, name, obj, document);
		}

		static void fromDocument(const typename TREE::Node &node, T *obj, typename TREE::Document *document)
		{
			TREE::getSimple(node, obj, document);
		}
	};
} // namespace season::parsing

template <class TREE>
class Season
{
public:
	template<class T>
	static std::string toJSON(const T &obj)
	{
		TREE::Document d;
		TREE::setObjectType(&d);
		parsing::ConvertNode<TREE, T>::toDocument("d", obj, &d, &d);
		return TREE::toString(d);
	}

	template<class T>
	static void fromJSON(const std::string &jsonStr, T *obj)
	{
		fromJSON(jsonStr.c_str(), obj);
	}

	template<class T>
	static void fromJSON(const char *jsonStr, T *obj)
	{
		TREE::Document document;
		TREE::parse(jsonStr, &document);
		const TREE::Node *node = TREE::getNode(document, "d");
		parsing::ConvertNode<TREE, T>::fromDocument(*node, obj, &document);
	}
};

} // namespace season

#ifdef ENSEED_SEASON_ENABLE_BOOST
#include "Extensions/boost.h"
#endif

#ifdef ENSEED_SEASON_ENABLE_STD
#include "Extensions/std.h"
#endif

#ifdef ENSEED_SEASON_ENABLE_CPP_NETLIB
#include "Extensions/cpp-netlib.h"
#endif

#ifdef ENSEED_SEASON_ENABLE_ENSEED
#include "Extensions/Enseed.h"
#endif
