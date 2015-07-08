#pragma once

#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>

#include "Season.h"

namespace season {

struct BoostTree
{
public:
	typedef boost::property_tree::ptree Document;
	typedef boost::property_tree::ptree Value;

	static void setObjectType(Value *value)
	{}

	template<class T>
	static void addMember(Value *value, const char *key, const T &v, Document *document)
	{
		value->AddMember(key, v, document->GetAllocator());
	}

	template<class T>
	static void setSimple(Value *node, const char *name, const T &value, Document *document)
	{
		if (name == nullptr)
		{
			// array element
			boost::property_tree::ptree elemTree;
			elemTree.put<T>("", value);
			node->push_back(std::make_pair("", elemTree));
		}
		else
		{
			node->put<T>(name, value);
		}
	}

	static void setString(Value *node, const char *name, const char *value, Document *document)
	{
		setSimple(node, name, value, document);
	}

	static std::string toString(const boost::property_tree::ptree &document)
	{
		std::stringstream strm;
		boost::property_tree::write_json(strm, document);
		return strm.str();
	}
};

typedef Season<BoostTree> BoostSeason;

} // namespace season