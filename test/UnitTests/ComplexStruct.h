#pragma once

#pragma once

#include <string>
#include <vector>
#include <map>
#include <boost/optional.hpp>
#include <boost/date_time/posix_time/ptime.hpp>
#include <boost/uuid/uuid.hpp>
#include <network/uri.hpp>
#include <memory>

struct SubComplexStruct
{
	std::string mySubStructure;
	std::shared_ptr<int> sharedIntPtr;
};

struct ComplexStruct
{
	int intValue;
	std::string stringValue;
	std::vector<int> vectorOfInt;
	std::map<std::string, std::shared_ptr<int>> mapOfSharedInt;
	std::map<std::string, int> mapOfInt;
	boost::optional<int> optionalInt;
	SubComplexStruct subStruct;
	boost::posix_time::ptime timeValue;
	boost::uuids::uuid uuidValue;
	network::uri uriValue;
};
