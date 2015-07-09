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
	};

	template<class TREE, class T>
	struct TConvertNode<TREE, std::vector<T>, Kind::COMPLEX>
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
	};

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
	};

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
	};

	template<class TREE, class T>
	struct TConvertNode<TREE, std::unique_ptr<T>, Kind::COMPLEX>
	{
		static void toDocument(const char *name, const std::unique_ptr<T> &objPtr, typename TREE::Document *document, typename TREE::Node *node)
		{
			if (objPtr)
			{
				ConvertNode<TREE, T>::toDocument(name, *objPtr, document, node);
			}
		}
	};

	template<class TREE>
	struct TConvertNode<TREE, std::string, Kind::COMPLEX>
	{
		static void toDocument(const char *name, const std::string &obj, typename TREE::Document *document, typename TREE::Node *node)
		{
			TREE::setString(node, name, obj.c_str(), document);
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
				ConvertNode<TREE, decltype(value)>::toDocument(key, value, document, &mapNode);
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
				ConvertNode<TREE, decltype(value)>::toDocument(name, value, document, &objNode);
			});
			TREE::addNode(node, name, &objNode, document);
		}

		static void toDocument(const char *name, const T &obj, typename TREE::Document *document, typename TREE::Node *node)
		{
			// distinguish between types and map objects
			toDocumentImpl(name, obj, document, node);
		}
	};

	template<class TREE, class T>
	struct TConvertNode<TREE, T, Kind::SIMPLE>
	{
		static void toDocument(const char *name, const T &obj, typename TREE::Document *document, typename TREE::Node *node)
		{
			TREE::setSimple(node, name, obj, document);
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
};
