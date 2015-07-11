#pragma once

#include "Season.h"

#include <rapidjson/document.h>
#include <rapidjson/prettywriter.h>
#include <rapidjson/stringbuffer.h>

namespace season {

template<class T>
struct NodeValueGetter
{};

template<>
struct NodeValueGetter<int>
{
	static int get(const rapidjson::Value &node)
	{
		return node.GetInt();
	}
};

struct RapidJSONTree
{
public:
	typedef rapidjson::Document Document;
	typedef rapidjson::Value Node;
	typedef rapidjson::Value::MemberIterator AttributeIterator;
	typedef rapidjson::Value::ConstMemberIterator ConstAttributeIterator;
	typedef rapidjson::Value::ValueIterator ArrayIterator;
	typedef rapidjson::Value::ConstValueIterator ConstArrayIterator;

	template<class T>
	static void addMember(Node *value, const char *name, const T &v, Document *document)
	{
		rapidjson::GenericValue<rapidjson::UTF8<> >::StringRefType key(name);
		value->AddMember(key, v, document->GetAllocator());
	}

	template<class T>
	static void setSimple(Node *node, const char *name, const T &value, Document *document)
	{
		if (name == nullptr)
		{
			node->PushBack(value, document->GetAllocator());
		}
		else
		{
			node->AddMember(rapidjson::StringRef(name), value, document->GetAllocator());
		}
	}

	template<class T>
	static void getSimple(const Node &node, T *value, Document *document)
	{
		*value = NodeValueGetter<T>::get(node);
	}

	static void setStringRef(Node *node, const char *name, const char *value, Document *document)
	{
		if (name == nullptr)
		{
			node->PushBack(rapidjson::StringRef(value), document->GetAllocator());
		}
		else
		{
			node->AddMember(rapidjson::StringRef(name), rapidjson::StringRef(value), document->GetAllocator());
		}
	}

	static void setString(Node *node, const char *name, const char *value, Document *document)
	{
		if (name == nullptr)
		{
			node->PushBack(rapidjson::Value(value, document->GetAllocator()), document->GetAllocator());
		}
		else
		{
			node->AddMember(rapidjson::StringRef(name), rapidjson::Value(value, document->GetAllocator()), document->GetAllocator());
		}
	}

	static void getString(const Node &node, std::string *value, Document *document)
	{
		*value = node.GetString();
	}

	static void setObjectType(Node *node)
	{
		node->SetObject();
	}

	static void setArrayType(Node *node)
	{
		node->SetArray();
	}

	static void addNode(Node *parent, const char *name, Node *child, Document *document)
	{
		if (name == nullptr)
		{
			parent->PushBack(*child, document->GetAllocator());
		}
		else
		{
			parent->AddMember(rapidjson::StringRef(name), *child, document->GetAllocator());
		}
	}

	static std::string toString(const Document &document)
	{
		rapidjson::StringBuffer buffer;
		rapidjson::PrettyWriter<rapidjson::StringBuffer> writer(buffer);
		document.Accept(writer);

		return buffer.GetString();
	}

	static void parse(const char *str, Document *document)
	{
		document->Parse(str);
	}

	static const Node* getNode(const Node &node, const char *name)
	{
		if (!node.IsObject())
			return nullptr;

		rapidjson::Value::ConstMemberIterator found = node.FindMember(name);
		if (found == node.MemberEnd())
			return nullptr;

		return &found->value;
	}

	static size_t getSize(const Node &node)
	{
		return node.Size();
	}

	static bool hasMember(const Node &node, const char *name)
	{
		return node.HasMember(name);
	}

	static auto arrayBegin(const Node &node)
	{
		return node.Begin();
	}
	static auto arrayEnd(const Node &node)
	{
		return node.End();
	}

	static auto attributeBegin(const Node &node)
	{
		return node.MemberBegin();
	}

	static auto attributeEnd(const Node &node)
	{
		return node.MemberEnd();
	}

	static const char *getIterName(const rapidjson::Value::ConstMemberIterator &iter)
	{
		return iter->name.GetString();
	}

	static const rapidjson::Value& getIterValue(const rapidjson::Value::ConstMemberIterator &iter)
	{
		return iter->value;
	}

	static const rapidjson::Value& getIterValue(const rapidjson::Value::ConstValueIterator &iter)
	{
		return *iter;
	}

	static bool isEmpty(const rapidjson::Value &node)
	{
		return node.GetType() != rapidjson::Type::kNullType;
	}

};


typedef Season<RapidJSONTree> RapidSeason;

} // namespace season
