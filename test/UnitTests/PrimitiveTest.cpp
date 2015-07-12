#include "Precompiled.h"

#include "gtest/gtest.h"
#include <boost/algorithm/string.hpp>
#include "Season.h"
#include "RapidSeason.h"
#include "BoostSeason.h"
#include "Tests.h"


template <class TREE>
void TestReadAllPrimitives()
{
	TestRead<TREE>((int8_t)1, "{d:1}");
	TestRead<TREE>((uint8_t)1, "{d:1}");
	TestRead<TREE>((int16_t)1, "{d:1}");
	TestRead<TREE>((uint16_t)1, "{d:1}");
	TestRead<TREE>((int32_t)1, "{d:1}");
	TestRead<TREE>((uint32_t)1, "{d:1}");
	TestRead<TREE>((int64_t)1, "{d:1}");
	TestRead<TREE>((uint64_t)1, "{d:1}");
	TestRead<TREE>((float)1.5, "{d:1.5}");
	TestRead<TREE>((double)1.5, "{d:1.5}");
}

TEST(EmptyTest, ReadPrimitive_RapidSeason)
{
	TestReadAllPrimitives<season::RapidJSONTree>();
}

TEST(EmptyTest, ReadInt_BoostSeason)
{
	TestReadAllPrimitives<season::BoostTree>();
}

