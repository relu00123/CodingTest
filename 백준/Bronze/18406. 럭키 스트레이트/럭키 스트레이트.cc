#include <bits/stdc++.h>

using namespace std;

int main()
{
	string input;

	std::cin >> input;

	int cal_1 = 0;
	int cal_2 = 0;

	int size = input.size() / 2;

	for (int i = 0; i < size; ++i)
	{
		cal_1 += (input[i] - '0');
	}

	for (int i = size; i < input.size(); ++i)
	{
		cal_2 += (input[i] - '0');
	}

	if (cal_1 == cal_2)
	{
		std::cout << "LUCKY" << std::endl;
	}

	else
	{
		std::cout << "READY" << std::endl;
	}

	return 0;
}