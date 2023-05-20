#include <bits/stdc++.h>

using namespace std;

int main()
{
	int command_count;

	vector<std::string> Stack;
	

	cin >> command_count;

	for (int i = 1; i <= command_count + 1; ++i)
	{

		string str;

		std::getline(std::cin, str);

		//std::cout << str << std::endl;

		istringstream ss(str);


		string buff;

		getline(ss, buff, ' ');

		// 어떤 명령인지 확인
		if (buff == "push")
		{
			getline(ss, buff);

			Stack.push_back(buff);

		}
		else if (buff == "pop")
		{
			if (Stack.size() == 0)
			{
				std::cout << -1 << "\n";
			}

			else
			{
				std::cout << Stack.back() << "\n";
				Stack.pop_back();
			}


		}
		else if (buff == "size")
		{
			std::cout << Stack.size() << "\n";
		}
		else if (buff == "empty")
		{
			if (Stack.size() == 0)
			{
				std::cout << 1 << "\n";
			}

			else
			{
				std::cout << 0 << "\n";
			}
		}
		else if (buff == "top")
		{
			if (Stack.size() == 0)
			{
				std::cout << -1 << "\n";
			}

			else
			{
				std::cout << Stack.back() << "\n";
			}
		}
	}

	

	return 0;
}