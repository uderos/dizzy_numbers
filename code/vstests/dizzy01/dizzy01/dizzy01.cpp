// dizzy01.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "dizzyGenerator.h"

static void f_test_sum_squares(const int number, const int base)
{
	dizzyGenerator dg;
	const int sum2 = dg.calc_sum_squares(number, base);
	std::cout << "SumSquares: num=" << number << " sum2=" << sum2 << std::endl;
}

static void f_test_dizzy_cycle(const int number, const int base)
{
	dizzyGenerator dg;
	const auto cycle = dg.dizziness_cycle(number, base);
	std::cout << "Cycle: num=" << number << " cycle=";
	for (const auto n : cycle)
		std::cout << n << " ";
	std::cout << std::endl;
}

static void f_test_dizzy_set(const int number, const int base)
{
	dizzyGenerator dg;
	const auto dizzy_set = dg.calculate_dizziness_set(number, base);
	std::cout << "Set:   num=" << number << "   set=";
	for (const auto n : dizzy_set)
		std::cout << n << " ";
	std::cout << std::endl;
}

static void f_test_dizzy_number(const int number, const int base)
{
	dizzyGenerator dg;
	const bool is_dizzy = dg.is_dizzy(number, base);
	std::cout << "The number " << number
		<< (is_dizzy ? " IS" : " is NOT")
		<< " dizzy" << std::endl;
}

static void f_test_find_dizzy_up_to(int last, const int base)
{
	dizzyGenerator dg;
	const auto dizzy_list = dg.find_dizzy_up_to(last, base);
	std::cout << "List: last=" << last << " list=";
	for (const auto n : dizzy_list)
		std::cout << n << " ";
	std::cout << std::endl;
}

static void f_test01()
{
	std::cout << __FUNCTION__ << "() BEGIN" << std::endl;
	f_test_sum_squares(123, 10);
	f_test_sum_squares(10, 3);
	f_test_sum_squares(12, 3);
	f_test_sum_squares(2, 3);
}

static void f_test02()
{
	std::cout << __FUNCTION__ << "() BEGIN" << std::endl;
	f_test_dizzy_cycle(12, 3);
	f_test_dizzy_set(12, 3);

	f_test_dizzy_cycle(68, 10);
	f_test_dizzy_set(68, 10);

	f_test_dizzy_cycle(90, 10);
	f_test_dizzy_set(90, 10);
}

static void f_test03()
{
	std::cout << __FUNCTION__ << "() BEGIN" << std::endl;

	f_test_dizzy_cycle(68, 10);		// happy / dizzy
	f_test_dizzy_number(68, 10);

	f_test_dizzy_cycle(964, 10);	// happy / dizzy
	f_test_dizzy_number(964, 10);

	f_test_dizzy_cycle(883, 10);	// happy / dizzy
	f_test_dizzy_number(883, 10);

	f_test_dizzy_cycle(2, 10);		// NOT happy / dizzy
	f_test_dizzy_number(2, 10);

	f_test_dizzy_cycle(999, 10);	// NOT happy / dizzy
	f_test_dizzy_number(999, 10);
}

static void f_test04()
{
	std::cout << __FUNCTION__ << "() BEGIN" << std::endl;

	f_test_find_dizzy_up_to(10, 10);
	f_test_find_dizzy_up_to(100, 10);
}

int _tmain(int argc, _TCHAR* argv[])

{
	f_test01();
	f_test02();
	f_test03();
	f_test04();

	return 0;
}

