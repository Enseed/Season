#include "MyStructure.h"
#include "MyStructure.h.reflect.h"
#include "BoostSeason.h"
#include "RapidSeason.h"
#include <iostream>

#include <boost/timer/timer.hpp>
#include <boost/uuid/uuid_generators.hpp>

int main(int argc, const char *argv[])
{
#if 1

	MyStructure s;
	s.intValue = 123;
	s.stringValue = "abc";
	s.vectorOfInt.push_back(1);
	s.vectorOfInt.push_back(2);
	s.vectorOfInt.push_back(3);
	s.mapOfInt["foo"] = 123;
	s.optionalInt.emplace(999);
	s.timeValue = boost::posix_time::second_clock::local_time();
	s.subStruct.sharedIntPtr.reset(new int(777));
	s.uuidValue = boost::uuids::random_generator()();

	{
		boost::timer::auto_cpu_timer timer;

		int len = 0;
		int count = 0;
		while (timer.elapsed().wall < 1000000000)
		{
			len += season::RapidSeason::toJSON(s).length();
			++count;
		}

		std::cout << count << " iterations / second using RapidSeason" << std::endl;
		std::cout << season::RapidSeason::toJSON(s) << std::endl;
	}
	{
		boost::timer::auto_cpu_timer timer;

		int len = 0;
		int count = 0;
		while (timer.elapsed().wall < 1000000000)
		{
			len += season::BoostSeason::toJSON(s).length();
			++count;
		}

		std::cout << count << " iterations / second using BoostSeason" << std::endl;
		std::cout << season::BoostSeason::toJSON(s) << std::endl;
	}
#endif // 0

	const std::string json = "{ \"d\": { \"intValue\": 123, \"stringValue\" : \"abc\", \"vectorOfInt\" : [ 1, 2, 3 ], \"mapOfInt\" : { \"foo\": 123 }, \"optionalInt\" : 70938, \"subStruct\" : { \"sharedIntPtr\": 777 } } }";

	{
		boost::timer::auto_cpu_timer timer;

		int len = 0;
		int count = 0;
		while (timer.elapsed().wall < 1000000000)
		{
			MyStructure t;
			season::RapidSeason::fromJSON(json, &t);
			++count;
		}

		std::cout << count << " iterations / second using RapidSeason" << std::endl;
		//std::cout << season::RapidSeason::toJSON(s) << std::endl;
	}
	{
		boost::timer::auto_cpu_timer timer;

		int len = 0;
		int count = 0;
		while (timer.elapsed().wall < 1000000000)
		{
			MyStructure t;
			season::BoostSeason::fromJSON(json, &t);
			++count;
		}

		std::cout << count << " iterations / second using BoostSeason" << std::endl;
		//std::cout << season::RapidSeason::toJSON(s) << std::endl;
	}
	return 0;
}