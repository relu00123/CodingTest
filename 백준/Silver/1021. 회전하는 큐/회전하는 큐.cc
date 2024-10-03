#include <bits/stdc++.h>
using namespace std;

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(0);


	deque<int> q; 
	int n, m; cin >> n >> m;

	for (int i = 1; i <= n; ++i)
		q.push_back(i);

	int ans = 0;

	while (m--)
	{
		int temp; cin >> temp;

		int front_cnt = 0;

		while (temp != q.front())
		{
			int cur = q.front();
			q.pop_front();
			q.push_back(cur);

			front_cnt += 1;
		}

		if (q.size() - front_cnt > front_cnt)
			ans += front_cnt;
		else
			ans += (q.size() - front_cnt);

		// 해당하는 숫자 제거
		q.pop_front();
	}

	cout << ans << "\n";

	return 0;

}