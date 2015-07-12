#include "Precompiled.h"
#include "ComplexStruct.h"
#include "ComplexStruct.h.reflect.h"

#include "gtest/gtest.h"
#include "RapidSeason.h"
#include "BoostSeason.h"
#include "Tests.h"

#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_io.hpp>
#include <boost/uuid/random_generator.hpp>

static inline void InitComplexStruct(ComplexStruct *obj)
{

	obj->intValue = 123;
	obj->stringValue = "abc";
	obj->vectorOfInt.push_back(1);
	obj->vectorOfInt.push_back(2);
	obj->vectorOfInt.push_back(3);
	obj->mapOfInt["foo"] = 123;
	obj->optionalInt.emplace(999);

	boost::gregorian::date date(boost::gregorian::greg_year_month_day(1999, 12, 31));
	obj->timeValue = boost::posix_time::ptime(date);

	obj->subStruct.sharedIntPtr.reset(new int(777));

	uint8_t data[] = { 0x01, 0x04, 0xa7, 0xb6, 0x02, 0x9f, 0x4b, 0xcd, 0xb8, 0x23, 0x0d, 0x75, 0x78, 0x3c, 0xcc, 0xfb };
	memcpy(&obj->uuidValue.data[0], data, 16);

	obj->uriValue = network::uri("https://www.google.com/");
}

TEST(ComplexStructTest, Read_RapidSeason)
{
	ComplexStruct obj;
	InitComplexStruct(&obj);



	TestRead<season::RapidJSONTree, decltype(obj)>(obj, "{d:{intValue:123,stringValue:abc,vectorOfInt:[1,2,3],mapOfSharedInt:{},mapOfInt:{foo:123},optionalInt:999,subStruct:{mySubStructure:,sharedIntPtr:777},timeValue:1999-12-31T00:00:00,uuidValue:0104a7b6-029f-4bcd-b823-0d75783cccfb,uriValue:https://www.google.com/}}");
}

TEST(ComplexStructTest, Read_BoostSeason)
{
	ComplexStruct obj;
	InitComplexStruct(&obj);

	TestRead<season::BoostTree, decltype(obj)>(obj, "{d:{intValue:123,stringValue:abc,vectorOfInt:[1,2,3],mapOfSharedInt:,mapOfInt:{foo:123},optionalInt:999,subStruct:{mySubStructure:,sharedIntPtr:777},timeValue:1999-12-31T00:00:00,uuidValue:0104a7b6-029f-4bcd-b823-0d75783cccfb,uriValue:https:\\/\\/www.google.com\\/}}");
}