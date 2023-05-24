#include <bits/stdc++.h>

using namespace std;

int main()
{
	int number;
	int temp;
	std::cin >> number;

	deque<int> Buffer;

	for (int i = 1;  i <= number; ++i)
	{
		Buffer.push_back(i);
	}

	while (Buffer.size() != 1)
	{


		Buffer.pop_front();
		temp = Buffer.front();
		Buffer.pop_front();
		Buffer.push_back(temp);

	}

	std::cout << *(Buffer.begin()) << std::endl;

	return 0;

}