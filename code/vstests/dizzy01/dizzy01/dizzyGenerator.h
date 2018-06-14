#pragma once
struct dizzyGenerator
{
public:
	dizzyGenerator();
	~dizzyGenerator();


	std::vector<int> find_dizzy_up_to(int last, const int base = 10);

	std::vector<int> dizziness_cycle(int number, int base = 10);

	bool is_dizzy(int number, int base = 10);


	//////// Utility methods

	int calc_sum_squares(int number, int base = 10);
	std::unordered_set<int> calculate_dizziness_set(int number, int base = 10);

};

