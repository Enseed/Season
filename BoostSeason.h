#pragma once

#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>

#include "Season.h"

namespace season {

struct BoostTree
{
public:
	typedef boost::property_tree::ptree Document;
	typedef boost::property_tree::ptree Node;
	typedef boost::property_tree::ptree::const_iterator ConstAttributeIterator;
	typedef boost::property_tree::ptree::iterator AttributeIterator;
	typedef boost::property_tree::ptree::const_iterator ConstArrayIterator;
	typedef boost::property_tree::ptree::iterator ArrayIterator;

	static void setObjectType(Node *value)
	{}

	template<class T>
	static void addMember(Node *value, const char *key, const T &v, Document *document)
	{
		value->AddMember(key, v, document->GetAllocator());
	}

	template<class T>
	static void setSimple(Node *node, const char *name, const T &value, Document *document)
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

	static void setString(Node *node, const char *name, const std::string &value, Document *document)
	{
		setSimple(node, name, value, document);
	}

	static void setStringRef(Node *node, const char *name, const char *value, Document *document)
	{
		setSimple(node, name, value, document);
	}

	static void addNode(Node *parent, const char *name, Node *child, Document *document)
	{
		if (name == nullptr)
		{
			parent->push_back(std::make_pair("", *child));
		}
		else
		{
			parent->push_back(std::make_pair(name, *child));
		}
	}


	static std::string toString(const boost::property_tree::ptree &document)
	{
		std::stringstream strm;
		boost::property_tree::write_json(strm, document);
		return strm.str();
	}

	static void setArrayType(Node *node)
	{}

	static void parse(const char *jsonStr, Document *doc)
	{
		std::stringstream strm;
		strm << jsonStr;
		boost::property_tree::read_json(strm, *doc);
	}

	static const Node* getNode(const Node &node, const char *name)
	{
		auto found = node.get_child_optional(name);
		if (found)
			return &(found.get());

		return nullptr;
	}

	static bool isEmpty(const Node &node)
	{
		return node.empty();
	}

	static size_t getSize(const Node &node)
	{
		return node.size();
	}

	static const boost::property_tree::ptree::const_iterator arrayBegin(const Node &node)
	{
		return node.begin();
	}

	static const boost::property_tree::ptree::const_iterator arrayEnd(const Node &node)
	{
		return node.end();
	}

	static const boost::property_tree::ptree::const_iterator attributeBegin(const Node &node)
	{
		return node.begin();
	}

	static const boost::property_tree::ptree::const_iterator attributeEnd(const Node &node)
	{
		return node.end();
	}


	static void getString(const Node &node, std::string *value, Document *document)
	{
		*value = node.get_value<std::string>();
	}

	template<class T>
	static void getSimple(const Node &node, T *value, Document *document)
	{
		*value = node.get_value<T>();
	}

	static const char* getIterName(const boost::property_tree::ptree::const_iterator &iter)
	{
		return iter->first.c_str();
	}

	static const Node& getIterValue(const boost::property_tree::ptree::const_iterator &iter)
	{
		return iter->second;
	}

};

typedef Season<BoostTree> BoostSeason;

} // namespace season