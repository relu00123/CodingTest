#include <bits/stdc++.h>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	
	int t; cin >> t;

	while (t--)
	{
		string input; cin >> input;

		list<char> answer;

		list<char>::iterator iter = answer.begin();

		for (char cur : input)
		{
			if (cur == '<')
			{
				if (iter != answer.begin())
					iter--;
			}

			else if (cur == '>')
			{
				if (iter != answer.end())
					iter++;
			}

			else if (cur == '-')
			{
				if (iter != answer.begin())
				{
					iter--;
					iter = answer.erase(iter);
				}
			}

			else
			{
				answer.insert(iter, cur);
			}
		}

		for (char e : answer)
			cout << e;

		cout << "\n";
	}

 


	return 0;
}