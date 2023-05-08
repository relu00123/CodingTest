#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	int zero_count = 0;
	int one_count = 0;

	char recent_num = '2';


	string str;

	std::cin >> str;

	for (int i = 0; i < str.size(); ++i)
	{
		if (str[i] == recent_num)
		{

		}

		else if (str[i] == '1')
		{
			recent_num = '1';
			one_count += 1;
		}

		else if (str[i] == '0')
		{
			recent_num = '0';
			zero_count += 1;
		}
	}

	if (zero_count >= one_count)
	{
		std::cout << one_count << std::endl;
	}

	else
	{
		std::cout << zero_count << std::endl;
	}
} 