#include <bits/stdc++.h>

using namespace std;

int main()
{
	int number;
	float max_score = 0;
	int total_score = 0;

	std::cin >> number;

	int*  arr = new int[number];


	for (int i = 0; i < number; ++i)
	{
		std::cin >> arr[i];
		if (arr[i] > max_score)
			max_score = arr[i];
	}

	 


	for (int i = 0; i < number; ++i)
	{
		total_score += arr[i] * 100;
	}

	std::cout << (float)total_score / number / max_score << std::endl;



	delete []arr;
}