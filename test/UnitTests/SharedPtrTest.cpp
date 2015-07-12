#include "Precompiled.h"


#include "gtest/gtest.h"
#include "RapidSeason.h"
#include "BoostSeason.h"
#include "Tests.h"

#include <memory>

TEST(SharedPtrTest, Read_RapidSeason)
{
	std::shared_ptr<int> obj(new int(5));
	TestRead<season::RapidJSONTree, decltype(obj)>(obj, "{d:5}");
}

TEST(SharedPtrTest, Read_BoostSeason)
{
	std::shared_ptr<int> obj(new int(5));
	TestRead<season::BoostTree, decltype(obj)>(obj, "{d:5}");
}