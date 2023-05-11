#include <bits/stdc++.h>

using namespace std;

int main()
{
	int hr;
	int min;

	std::cin >> hr;
	std::cin >> min;

	int total_num = 60 * hr + min;

	if (total_num - 45 < 0)
	{
		total_num = total_num - 45 + (24 * 60);
	}

	else
	{
		total_num = total_num - 45;
	}

	int out_x;
	int out_y;

	out_x = total_num / 60;
	out_y = total_num % 60;

	std::cout << out_x << " " << out_y << std::endl;



	return 0;
}