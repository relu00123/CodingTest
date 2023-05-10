#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	int total_num = 0;

	std::cin >> n;


	string input;

	std::cin >> input;

	for (int i = 0; i < input.size(); ++i)
	{
		total_num += (input[i] - '0');
	}

	std::cout << total_num << std::endl;


	return 0;
}