#pragma once

#include "Season.h"

#include <rapidjson/document.h>
#include <rapidjson/prettywriter.h>
#include <rapidjson/stringbuffer.h>

namespace season {

struct RapidJSONTree
{
public:
	typedef rapidjson::Document Document;
	typedef rapidjson::Value Value;

	template<class T>
	static void addMember(Value *value, const char *name, const T &v, Document *document)
	{
		rapidjson::GenericValue<rapidjson::UTF8<> >::StringRefType key(name);
		value->AddMember(key, v, document->GetAllocator());
	}

	template<class T>
	static void setSimple(Value *node, const char *name, const T &value, Document *document)
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

	static void setString(Value *node, const char *name, const char *value, Document *document)
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

	static void setObjectType(Value *value)
	{
		value->SetObject();
	}

	static std::string toString(const Document &document)
	{
		rapidjson::StringBuffer buffer;
		rapidjson::PrettyWriter<rapidjson::StringBuffer> writer(buffer);
		document.Accept(writer);

		return buffer.GetString();
	}
};


typedef Season<RapidJSONTree> RapidSeason;

} // namespace season
