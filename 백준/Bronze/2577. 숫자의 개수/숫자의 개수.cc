#include <bits/stdc++.h>

using namespace std;

int main()
{
	int num_count[10] = { 0 };

	int first;
	int second;
	int third;
	int total;

	std::cin >> first;
	std::cin >> second;
	std::cin >> third;

	total = first * second * third;

	while (total / 10 != 0)
	{
		num_count[total % 10] += 1;
		total = total / 10;
	}

	num_count[total] += 1;

	for (int i = 0; i <= 9; ++i)
	{
		std::cout << num_count[i] << std::endl;
	}

	return 0;
}