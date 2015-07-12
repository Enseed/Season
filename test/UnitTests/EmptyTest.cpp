#include "Precompiled.h"

#include "gtest/gtest.h"
#include "Empty.h"
#include "Empty.h.reflect.h"
#include "RapidSeason.h"
#include "BoostSeason.h"
#include "Tests.h"

TEST(PrimitiveTest, Read_RapidSeason)
{
	Empty e;
	TestRead<season::RapidJSONTree, Empty>(e, "{d:{}}");
}

TEST(PrimitiveTest, Read_BoostSeason)
{
	Empty e;
	TestRead<season::BoostTree, Empty>(e, "{d:}");
}