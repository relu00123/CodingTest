#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n; cin >> n;

	deque<int> dq;

	while (n--)
	{
		string order; cin >> order;

		if (order == "push")
		{
			int temp; cin >> temp;
			dq.push_back(temp);
		}

		else if (order == "pop")
		{
			if (dq.size() != 0)
			{
				cout << dq.front() << "\n";
				dq.pop_front();
			}
			else
			{
				cout << "-1\n";
			}
		}

		else if (order == "size")
		{
			cout << dq.size() << "\n";
		}

		else if (order == "empty")
		{
			if (dq.empty())
			{
				cout << "1\n";
			}
			else
			{
				cout << "0\n";
			}
		}

		else if (order == "front")
		{
			if (dq.empty())
				cout << "-1\n";
			else
				cout << dq.front() << "\n";
		}

		else if (order == "back")
		{
			if (dq.empty())
				cout << "-1\n";
			else
				cout << dq.back() << "\n";
		}
	}

	return 0;
}