#include <bits/stdc++.h>

using namespace std;

int main()
{
	int left_count = 0;
	int right_count = 0;
	string input;

	bool skip = false;

	int num;

	std::cin >> num;

	for (int i = 1; i <= num; ++i)
	{
		std::cin >> input;

		for (int i = 0; i < input.size() ; ++i)
		{
			if (skip == false)
			{

				if (input[i] == '(')
				{
					left_count += 1;
				}

				else if (input[i] == ')')
				{
					if (left_count <= 0)
					{
						std::cout << "NO" << std::endl;
						skip = true;
					}

					else
					{
						left_count -= 1;
					}
				}
			}
		}

	
		if (skip != true)

		{
			if (left_count == 0)
			{
				std::cout << "YES" << std::endl;
			}
			else
			{
				std::cout << "NO" << std::endl;
			}
		}

		skip = false;
		left_count = 0;

	}

 
	return 0;
}