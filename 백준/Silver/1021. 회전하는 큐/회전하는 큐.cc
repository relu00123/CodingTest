#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m; cin >> n >> m;

	deque<int> dq;

	for (int i = 1; i <= n; ++i)
	{
		dq.push_back(i);
	}

	auto iter = dq.begin();

	int ans = 0;

	while (m--)
	{
		int target; cin >> target;

		auto plus_iter = iter;
		auto minus_iter = iter;
		int plus_cnt = 0;
		int minus_cnt = 0;

		while (*plus_iter != target)
		{
			plus_cnt++;

			if (plus_iter == dq.end())
				plus_iter = dq.begin();

			plus_iter++;
			if (plus_iter == dq.end())
				plus_iter = dq.begin();
		}

		while (*minus_iter != target)
		{
			minus_cnt++;
			 
			if (minus_iter == dq.begin())
			{
				minus_iter = dq.end() - 1;
			}
			else
			{
				minus_iter--;
			}
		}


		if (minus_cnt < plus_cnt)
		{
			// minus로 가야함 
			ans += minus_cnt;
			//iter = minus_iter;
			iter = dq.erase(minus_iter);
			if (iter == dq.end())
				iter = dq.begin();
		}

		else
		{
			ans += plus_cnt;
			iter = dq.erase(plus_iter);
			if (iter == dq.end())
				iter = dq.begin();
		}


	}

	cout << ans << "\n";

	return 0;
}