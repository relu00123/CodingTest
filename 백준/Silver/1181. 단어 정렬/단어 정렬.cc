#include <bits/stdc++.h>

using namespace std;

bool Compare(string _first, string _second)
{
	for (int i = 0; i < _first.size(); ++i)
	{
		if (_first[i] > _second[i])
		{
			return false;
		}

		else if (_first[i] < _second[i])
		{
			return true;
		}
	}

	return false;
}

int main()
{
	vector<string> input[51];

	int n;
	std::cin >> n;
	string temp;
	string buffer;

	for (int i = 1; i <= n; ++i)
	{
		std::cin >> temp;
		input[temp.size()].push_back(temp);
	}

	for (int i = 1; i <= 50; ++i)
	{
		sort(input[i].begin(), input[i].end(), Compare);
	}

	for (int i = 1; i <= 50; ++i)
	{
		vector<string>::iterator iter;

		for (iter = input[i].begin(); iter != input[i].end(); )
		{
			if (buffer == *iter)
			{
				iter = input[i].erase(iter);
			}

			else
			{
				buffer = *iter;
				iter++;
			}
		}
	}


	for (int i = 1; i <= 50; ++i)
	{
		for (int j = 0; j < input[i].size(); ++j)
		{
			std::cout << input[i][j] << std::endl;
		}
	}
 

	return 0;

}