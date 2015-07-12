#pragma once

#include <string>
#include <boost/algorithm/string.hpp>

static inline std::string StripJSON(const std::string &json)
{
	std::string result = json;
	auto end = std::remove_if(result.begin(), result.end(), ::isspace);
	result.erase(end, result.end());
	boost::replace_all(result, "\"", "");
	return result;
}

template <class TREE, class T>
void TestRead(const T &val, const std::string &expResult)
{
	std::string result = season::Season<TREE>::toJSON(val);
	result = StripJSON(result);
	EXPECT_EQ(result, expResult);
}
