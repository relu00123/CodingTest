#include <bits/stdc++.h>

using namespace std;

int main()
{
	int count = 1;

	string input;
	getline(cin, input);

	for (int i = 0; i < input.size(); ++i)
	{
		if (input[i] == ' ')
		{
			count += 1;
		}
	}


	if (input[0] == ' ')
		count -= 1;

	if (input[input.size() - 1] == ' ')
		count -= 1;


	std::cout << count << std::endl;

	return 0;

}