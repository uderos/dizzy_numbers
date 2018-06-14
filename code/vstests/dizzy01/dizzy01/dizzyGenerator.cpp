#include "stdafx.h"
#include "dizzyGenerator.h"


std::vector<int> dizzyGenerator::find_dizzy_up_to(int last, const int base /* = 10*/)
{
	std::vector<int> dizzy_list;

	for (int n = 1; n <= last; ++n)
		if (is_dizzy(n))
			dizzy_list.push_back(n);

	return dizzy_list;
}

std::vector<int> dizzyGenerator::dizziness_cycle(int number, int base /*= 10*/)
{
	const auto dizzy_set = calculate_dizziness_set(number, base);

	std::vector<int> dizzy_cycle;
	dizzy_cycle.reserve(dizzy_set.size());

	std::copy(dizzy_set.begin(), dizzy_set.end(), 
				std::inserter(dizzy_cycle, dizzy_cycle.begin()));

	return dizzy_cycle;
}

bool dizzyGenerator::is_dizzy(int number, int base /*= 10*/)
{
	const auto dizzy_set = calculate_dizziness_set(number, base);

	if (dizzy_set.empty()) throw std::runtime_error("Empty Cycle");

	const bool is_number_dizzy = (dizzy_set.find(1) != dizzy_set.end());

	return is_number_dizzy;
}

int dizzyGenerator::calc_sum_squares(int number, int base /*= 10*/)
{
	int sum2 = 0;
	while (number > 0)
	{
		const int digit = number % base;
		sum2 += (digit * digit);
		number = number / base;
	}
	return sum2;
}

std::unordered_set<int> dizzyGenerator::calculate_dizziness_set(int number, int base /*= 10*/)
{
	std::unordered_set<int> dizzy_set;

	for (;;)
	{
		const int sum2 = calc_sum_squares(number, base);
		if (dizzy_set.find(sum2) == dizzy_set.end())
		{
			dizzy_set.insert(sum2);
			number = sum2;
		}
		else
		{
			return dizzy_set;
		}
	};

	return dizzy_set;
}

