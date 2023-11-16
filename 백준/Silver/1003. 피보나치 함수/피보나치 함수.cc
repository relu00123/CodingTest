#include<bits/stdc++.h>
using namespace std;

int T;

// 0이 불린횟수, 1이 불린 횟수
vector<pair<long long int, long long int>> dp(41);


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);


	dp[0] = { 1, 0 };
	dp[1] = { 0, 1 };

	for (int i = 2; i < 41; ++i) {
		dp[i] = { dp[i - 1].first + dp[i - 2].first,
			dp[i - 1].second + dp[i - 2].second };
	}

	cin >> T;


	while (T--) {
		int temp;
		cin >> temp;

		cout << dp[temp].first << " " << dp[temp].second << "\n";
	}

	return 0;
} 