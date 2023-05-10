#include <bits/stdc++.h>

using namespace std;

int main()
{
	int index = 0;
	int number = 0;
	int temp;

	for (int i = 1; i <= 9; ++i)
	{
		std::cin >> temp;

		if (temp > number)
		{
			index = i;
			number = temp;
		}
	}
	

	std::cout << number << "\n" << index << std::endl;

	return 0;
}