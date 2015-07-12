#pragma once

struct SimpleStruct
{
	SimpleStruct()
		: a(0)
		, b(0)
	{}

	SimpleStruct(int ia, double ib)
		: a(ia)
		, b(ib)
	{}

	int a;
	double b;
};