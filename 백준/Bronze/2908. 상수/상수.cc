#include <bits/stdc++.h>

using namespace std;

int main()
{
	char first[4];
	char second[4];

	std::cin >> first;
	std::cin >> second;


	char new_first[4]; 
	new_first[0] = first[2];
	new_first[1] = first[1];
	new_first[2] = first[0];
	new_first[3] = '\0';


	char new_second[4];
	new_second[0] = second[2];
	new_second[1] = second[1];
	new_second[2] = second[0];
	new_second[3] = '\0';

	for (int i = 0; i <= 2; ++i)
	{
		if (new_first[i] > new_second[i])
		{
			std::cout << new_first << std::endl;
			return 0;
		}

		else if (new_second[i] > new_first[i])
		{
			std::cout << new_second << std::endl;
			return 0;
		}
	}

	return 0;
}