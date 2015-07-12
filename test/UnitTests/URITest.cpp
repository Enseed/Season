#include "Precompiled.h"


#include "gtest/gtest.h"
#include "RapidSeason.h"
#include "BoostSeason.h"
#include "Tests.h"

#include <cpp-netlib/uri/src/network/uri/uri.hpp>

TEST(URITest, Read_RapidSeason)
{
	network::uri obj("https://github.com/Enseed/Season");
	TestRead<season::RapidJSONTree, decltype(obj)>(obj, "{d:https://github.com/Enseed/Season}");
}

TEST(URITest, Read_BoostSeason)
{
	network::uri obj("https://github.com/Enseed/Season");
	TestRead<season::BoostTree, decltype(obj)>(obj, "{d:https:\\/\\/github.com\\/Enseed\\/Season}");
}