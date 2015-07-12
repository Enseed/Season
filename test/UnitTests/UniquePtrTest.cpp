#include "Precompiled.h"


#include "gtest/gtest.h"
#include "RapidSeason.h"
#include "BoostSeason.h"
#include "Tests.h"

#include <memory>

TEST(UniquePtrTest, Read_RapidSeason)
{
	std::unique_ptr<int> obj(new int(5));
	TestRead<season::RapidJSONTree, decltype(obj)>(obj, "{d:5}");
}

TEST(UniquePtrTest, Read_BoostSeason)
{
	std::unique_ptr<int> obj(new int(5));
	TestRead<season::BoostTree, decltype(obj)>(obj, "{d:5}");
}