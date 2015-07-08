#pragma once

#include <string>
#include <Enseed/Reflect/API/Class.h>

namespace parsing
{
	typedef enum
	{
		SIMPLE,
		COMPLEX,
		STRING
	} Kind;

	struct NodeTraits_Complex
	{
		static constexpr Kind kind = Kind::COMPLEX;
	};

	struct NodeTraits_Simple
	{
		static constexpr Kind kind = Kind::SIMPLE;
	};

	struct NodeTraits_String
	{
		static constexpr Kind kind = Kind::STRING;
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

	template<> class NodeTraits<std::string> : public NodeTraits_String{};

	template<class TREE, class T, int T_KIND=NodeTraits<T>::kind>
	struct ConvertNode
	{};

	template<class TREE, class T>
	struct ConvertNode<TREE, T, Kind::COMPLEX>
	{
		static void toDocument(const char *name, const T &obj, typename TREE::Document *document, typename TREE::Value *value)
		{
			//const char *name = reflect::Class<T>::name();
			TREE::setObjectType(value);
			reflect::Class<T>::visitFields([&obj, &document, &value](auto field) {
				ConvertNode<TREE, decltype(field)::type>::toDocument(decltype(field)::name(), decltype(field)::readRef(obj), document, value);
			});
		}
	};

	template<class TREE, class T>
	struct ConvertNode<TREE, T, Kind::STRING>
	{
		static void toDocument(const char *name, const T &obj, typename TREE::Document *document, typename TREE::Value *node)
		{
			TREE::setString(node, name, obj.c_str(), document);
		}
	};

	template<class TREE, class T>
	struct ConvertNode<TREE, T, Kind::SIMPLE>
	{
		static void toDocument(const char *name, const T &obj, typename TREE::Document *document, typename TREE::Value *node)
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
		parsing::ConvertNode<TREE, T>::toDocument(nullptr, obj, &d, &d);
		return TREE::toString(d);
	}
};
