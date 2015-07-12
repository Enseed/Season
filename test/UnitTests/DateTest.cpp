#include "Precompiled.h"

#include "gtest/gtest.h"
#include "RapidSeason.h"
#include "BoostSeason.h"
#include "Tests.h"

#include <boost/date_time/gregorian_calendar.hpp>
#include <boost/date_time/posix_time/ptime.hpp>

TEST(DateTest, Read_RapidSeason)
{
	boost::gregorian::date date(boost::gregorian::greg_year_month_day(1999, 12, 31));
	boost::posix_time::ptime obj(date);
	TestRead<season::RapidJSONTree, decltype(obj)>(obj, "{d:1999-12-31T00:00:00}");
}

TEST(DateTest, Read_BoostSeason)
{
	boost::gregorian::date date(boost::gregorian::greg_year_month_day(1999, 12, 31));
	boost::posix_time::ptime obj(date);
	TestRead<season::BoostTree, decltype(obj)>(obj, "{d:1999-12-31T00:00:00}");
}