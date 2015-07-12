#include "Precompiled.h"

#include "gtest/gtest.h"
#include "SimpleStruct.h"
#include "SimpleStruct.h.reflect.h"
#include "RapidSeason.h"
#include "BoostSeason.h"
#include "Tests.h"

TEST(SimpleStructTest, Read_RapidSeason)
{
	SimpleStruct s;
	s.a = 123;
	s.b = 4.25;

	TestRead<season::RapidJSONTree, SimpleStruct>(s, "{d:{a:123,b:4.25}}");
}

TEST(SimpleStructTest, Read_BoostSeason)
{
	SimpleStruct s;
	s.a = 123;
	s.b = 4.25;

	TestRead<season::BoostTree, SimpleStruct>(s, "{d:{a:123,b:4.25}}");
}