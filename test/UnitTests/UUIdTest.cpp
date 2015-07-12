#include "Precompiled.h"


#include "gtest/gtest.h"
#include "RapidSeason.h"
#include "BoostSeason.h"
#include "Tests.h"

#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_io.hpp>
#include <boost/uuid/random_generator.hpp>

TEST(UUIdTest, Read_RapidSeason)
{
	boost::uuids::uuid obj;
	uint8_t data[] = { 0x01, 0x04, 0xa7, 0xb6, 0x02, 0x9f, 0x4b, 0xcd, 0xb8, 0x23, 0x0d, 0x75, 0x78, 0x3c, 0xcc, 0xfb };
	memcpy(&obj.data[0], data, 16);
	TestRead<season::RapidJSONTree, decltype(obj)>(obj, "{d:0104a7b6-029f-4bcd-b823-0d75783cccfb}");
}

TEST(UUIdTest, Read_BoostSeason)
{
	boost::uuids::uuid obj;
	uint8_t data[] = { 0x01, 0x04, 0xa7, 0xb6, 0x02, 0x9f, 0x4b, 0xcd, 0xb8, 0x23, 0x0d, 0x75, 0x78, 0x3c, 0xcc, 0xfb };
	memcpy(&obj.data[0], data, 16);
	TestRead<season::BoostTree, decltype(obj)>(obj, "{d:0104a7b6-029f-4bcd-b823-0d75783cccfb}");
}