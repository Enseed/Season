#pragma once

#include <string>
#include <boost/date_time/posix_time/ptime.hpp>
#include <boost/date_time/posix_time/time_formatters.hpp>
#include <boost/date_time/posix_time/time_parsers.hpp>
#include <Reflect/Class.h>

namespace season
{
	namespace parsing
	{
		template<class TREE>
		struct ConvertComplexType<TREE, boost::posix_time::ptime>
		{
			static void toDocument(const char *name, const boost::posix_time::ptime &obj, typename TREE::Document *document, typename TREE::Node *node)
			{
				std::string value = boost::posix_time::to_iso_extended_string(obj);
				TREE::setString(node, name, value.c_str(), document);
			}

			static void fromDocument(const typename TREE::Node &node, boost::posix_time::ptime *obj, typename TREE::Document *document)
			{
				std::string strValue;
				TREE::getString(node, &strValue, document);
				*obj = boost::posix_time::time_from_string(strValue);
			}
		};
	}
}
