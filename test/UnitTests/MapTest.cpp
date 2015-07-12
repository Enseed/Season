#include "Precompiled.h"

#include "gtest/gtest.h"
#include "SimpleStruct.h"
#include "SimpleStruct.h.reflect.h"
#include "RapidSeason.h"
#include "BoostSeason.h"
#include "Tests.h"
#include <map>


TEST(MapTest, Read_RapidSeason)
{
	std::map<std::string, int> obj;
	obj.emplace(std::make_pair("a", 1));
	obj.emplace(std::make_pair("b", 2));
	obj.emplace(std::make_pair("c", 3));

	TestRead<season::RapidJSONTree, decltype(obj)>(obj, "{d:{a:1,b:2,c:3}}");
}

TEST(MapTest, Read_BoostSeason)
{
	std::map<std::string, int> obj;
	obj.emplace(std::make_pair("a", 1));
	obj.emplace(std::make_pair("b", 2));
	obj.emplace(std::make_pair("c", 3));

	TestRead<season::BoostTree, decltype(obj)>(obj, "{d:{a:1,b:2,c:3}}");
}