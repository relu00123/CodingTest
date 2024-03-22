#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n; cin >> n;

	// 0번째 인덱스에는 걸리는 시간, 1번째 인덱스에는 보수를 저장
	vector<int> time(n + 1);
	vector<int> cost(n + 1);

	// n일차에 받는 최대 보수
	vector<int> dp(n + 1);
	fill(dp.begin(), dp.end(), 0);

	for (int i = 1; i <= n; ++i)
		cin >> time[i] >> cost[i];

	dp[0] = 0;

	for (int i = 1; i <= n; ++i)
	{
		dp[i] = max(dp[i], dp[i - 1]);

		if (i + time[i] - 1 > n) continue;
		
		 
		dp[i + time[i] -1 ] = max(dp[i - 1] + cost[i], dp[i + time[i] - 1]);

		/*cout << i << ": ";
		for (int i = 1; i <= n; ++i)
		{
			cout << dp[i] << " ";
		}
		cout << "\n";*/

	}

	/*for (int i = 1; i <= n; ++i)
	{
		cout << dp[i] << " ";
	}*/

	cout << dp[n] << "\n";


	return 0;
}