#include <bits/stdc++.h>

using namespace std;

int main()
{
	int num;
	int repeat_num;
	string str;

	std::cin >> num;

	for (int i = 1; i <= num; ++i)
	{
		std::cin >> repeat_num;
		std::cin >> str;

		for (int j = 0; j < str.size(); ++j)
		{
			for (int k = 1; k <= repeat_num; ++k)
			{
				std::cout << str[j];
			}
		}

		std::cout << "\n";
	}

	return 0;

}