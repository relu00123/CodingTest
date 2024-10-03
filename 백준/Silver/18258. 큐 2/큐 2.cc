#include <bits/stdc++.h>
using namespace std;

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(0);


	int n; cin >> n;

	queue<int> q;

	while (n--)
	{
		string str; cin >> str;


		if (str == "front")
		{
			if (q.size() == 0)
				cout << "-1\n";
			else
				cout << q.front() << "\n";
		}

		else if (str == "back")
		{
			if (q.size() == 0)
				cout << "-1\n";
			else
				cout << q.back() << "\n";
		}

		else if (str == "size")
		{
			cout << q.size() << "\n";
		}

		else if (str == "empty")
		{
			if (q.size() == 0)
				cout << "1\n";
			else
				cout << "0\n";
		}

		else if (str == "pop")
		{
			if (q.size() == 0)
				cout << "-1\n";
			else
			{
				cout << q.front() << "\n";
				q.pop();
			}
		}

		else if (str == "push")
		{
			int temp; cin >> temp;
			q.push(temp);
		}

		

	}

}