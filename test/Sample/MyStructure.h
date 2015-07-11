#pragma once

#include <string>
#include <vector>
#include <map>
#include <boost/optional.hpp>
#include <boost/date_time/posix_time/ptime.hpp>
#include <boost/uuid/uuid.hpp>
#include <memory>

struct MySubStructure
{
	std::string mySubStructure;
	std::shared_ptr<int> sharedIntPtr;
};

struct MyStructure
{
	int intValue;
	std::string stringValue;
	std::vector<int> vectorOfInt;
	std::map<std::string, int> mapOfInt;
	boost::optional<int> optionalInt;
	MySubStructure subStruct;
	boost::posix_time::ptime timeValue;
	boost::uuids::uuid uuidValue;
};
