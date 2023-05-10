#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	int min_num = 0;
	int max_num = 0;
	

	std::cin >> n;

	if (n == 1)
	{
		int temp;

		std::cin >> temp;

		std::cout << temp << " " << temp << std::endl;
	}

	else
	{
		int temp;

		std::cin >> temp;

		min_num = temp;
		max_num = temp;

		for (int i = 2; i <= n; ++i)
		{
			std::cin >> temp;

			if (temp < min_num)
				min_num = temp;
			else if (temp > max_num)
				max_num = temp;
		}

		std::cout << min_num << " " << max_num << std::endl;

	}

	return 0;
}