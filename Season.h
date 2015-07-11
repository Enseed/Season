#pragma once

#include <string>
#include <Enseed/Reflect/API/Class.h>

namespace parsing
{
	typedef enum
	{
		SIMPLE,
		COMPLEX
	} Kind;

	struct NodeTraits_Complex
	{
		static constexpr Kind kind = Kind::COMPLEX;
	};

	struct NodeTraits_Simple
	{
		static constexpr Kind kind = Kind::SIMPLE;
	};

	template<class T> struct NodeTraits : public NodeTraits_Complex {};

	template<> class NodeTraits<char> : public NodeTraits_Simple{};
	template<> class NodeTraits<short> : public NodeTraits_Simple{};
	template<> class NodeTraits<int> : public NodeTraits_Simple{};
	template<> class NodeTraits<long> : public NodeTraits_Simple{};
	template<> class NodeTraits<long long> : public NodeTraits_Simple{};
	template<> class NodeTraits<bool> : public NodeTraits_Simple{};
	template<> class NodeTraits<float> : public NodeTraits_Simple{};
	template<> class NodeTraits<double> : public NodeTraits_Simple{};


	template<class TREE, class T, int T_KIND = NodeTraits<T>::kind>
	struct TConvertNode
	{};

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
	struct TConvertNode<TREE, T, Kind::COMPLEX>
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
	struct TConvertNode<TREE, T, Kind::SIMPLE>
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
}

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

#include "Extensions/boost/Optional.h"
#include "Extensions/std/Vector.h"
#include "Extensions/std/UniquePtr.h"
#include "Extensions/std/SharedPtr.h"
#include "Extensions/std/String.h"
#include "Extensions/boost/PosixTime.h"
#include "Extensions/boost/UUId.h"
