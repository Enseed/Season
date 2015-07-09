#include "MyStructure.h"
#include "MyStructure.h.reflect.h"
#include "BoostSeason.h"
#include "RapidSeason.h"
#include <iostream>

#include <boost/timer/timer.hpp>

int main(int argc, const char *argv[])
{
	MyStructure s;
	s.intValue = 123;
	s.stringValue = "abc";
	s.vectorOfInt.push_back(1);
	s.vectorOfInt.push_back(2);
	s.vectorOfInt.push_back(3);
	s.mapOfInt["foo"] = 123;
	s.optionalInt.emplace(999);
	s.subStruct.sharedIntPtr.reset(new int(777));

	{
		boost::timer::auto_cpu_timer timer;

		int len = 0;
		int count = 0;
		while (timer.elapsed().user < 1000000000)
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
		while (timer.elapsed().user < 1000000000)
		{
			len += season::BoostSeason::toJSON(s).length();
			++count;
		}

		std::cout << count << " iterations / second using BoostSeason" << std::endl;
		std::cout << season::BoostSeason::toJSON(s) << std::endl;
	}
	return 0;
}