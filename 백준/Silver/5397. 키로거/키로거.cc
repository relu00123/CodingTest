#include <bits/stdc++.h>
using namespace std;



int main()
{
	int n;
	std::cin >> n;
	//cin.ignore();

	vector<list<char>> pwd(n);


	for (int i = 0; i < n; ++i)
	{
		pwd[i].clear();


		string input;
		cin >> input;


		list<char>::iterator it;
		it = pwd[i].begin();


		for (auto j : input)
		{
			char cur_char = j;

			switch (cur_char)
			{
			case '-':
			{
				if (it != pwd[i].begin())
				{ 
					it--;
					it = pwd[i].erase(it);

			 
				}
			}
			break;
			case '>':
			{
				if (it != pwd[i].end())
					it++;
			}
			break;
			case '<':
			{
				if (it != pwd[i].begin())
					it--;
			}
			break;
			default:
			{
				pwd[i].insert(it, cur_char);
		
			}
				break;
			}
		}
	}

	for (int i = 0; i < pwd.size(); ++i)
	{
		for (auto character : pwd[i])
			cout << character;

		cout << "\n";
	}


	return 0;
}