#include "MyStructure.h"
#include "MyStructure.h.reflect.h"
#include "BoostSeason.h"
#include "RapidSeason.h"
#include <iostream>

int main(int argc, const char *argv[])
{
	MyStructure s;
	s.intValue = 123;
	s.stringValue = "abc";

	std::cout << season::BoostSeason::toJSON(s) << std::endl;
	std::cout << season::RapidSeason::toJSON(s) << std::endl;
	return 0;
}