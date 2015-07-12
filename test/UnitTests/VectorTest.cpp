#include "Precompiled.h"

#include "gtest/gtest.h"
#include "RapidSeason.h"
#include "BoostSeason.h"
#include "Tests.h"

TEST(VectorTest, Read_RapidSeason)
{
	std::vector<int> vs;
	vs.emplace_back(1);
	vs.emplace_back(2);
	vs.emplace_back(3);

	TestRead<season::RapidJSONTree, std::vector<int>>(vs, "{d:[1,2,3]}");
}

TEST(VectorTest, Read_BoostSeason)
{
	std::vector<int> vs;
	vs.emplace_back(1);
	vs.emplace_back(2);
	vs.emplace_back(3);

	TestRead<season::BoostTree, std::vector<int>>(vs, "{d:[1,2,3]}");
}