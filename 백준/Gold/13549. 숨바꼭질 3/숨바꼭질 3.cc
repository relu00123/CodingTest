#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

const int max_num = 1e9;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	// 수빈이는 현재 N지점에 있고, 동생은 K지점에 있다.
	// 수빈이는 걸을 수 있다. x-1 혹은 x+1  (1초의 시간 소요)
	// 순간이동시 0초이후에 2*x의 위치로 이동한다


	vector<int> dp(200'000, max_num);

	int su, dong; cin >> su >> dong;

	dp[su] = 0;
	queue<int> pos;
	pos.push(su);

	while (true) {
		int cur = pos.front(); pos.pop();
		if (cur == dong) break;

		// 순간이동 먼저하기
		if (cur * 2 < 200'000 && dp[2 * cur] > dp[cur]) {
			dp[2 * cur] = dp[cur];
			pos.push(2 * cur);
		}

		// 왼쪽으로 이동하기
		if (0 <= cur - 1 && dp[cur - 1] > dp[cur] + 1) {
			dp[cur - 1] = dp[cur] + 1;
			pos.push(cur - 1);
		}

		// 오른쪽으로 이동하기
		if (cur + 1 < 200000 && dp[cur + 1] > dp[cur] + 1) {
			dp[cur + 1] = dp[cur] + 1;
			pos.push(cur + 1);
		}
	}

	cout << dp[dong] << "\n";



	return 0;
}