#include <bits/stdc++.h>

using namespace std;

int main()
{
	int test_num;
	string input;
	int total_score = 0;
	int streak = 1;

	std::cin >> test_num;

	for (int i = 1; i <= test_num; ++i)
	{
		std::cin >> input;

		for (int j = 0; j < input.size(); ++j)
		{
			if (input[j] == 'O')
			{
				total_score += streak;
				streak += 1;
			}

			else if (input[j] == 'X')
			{
				streak = 1;
			}
		}

		std::cout << total_score << std::endl;
		streak = 1;
		total_score = 0;

	}

	return 0;
}