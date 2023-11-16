#include<bits/stdc++.h>
using namespace std;

int n;

// 0으로 끝나는 개수, 1으로 끝나는 개수
vector<pair<long long int, long long int>>  dp(91);

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;


	dp[1] = { 0, 1 };
	dp[2] = { 1, 0 };

	for (int i = 3; i <= n; ++i) {

		// 0 으로 끝나려면, 앞자리가 0 또는 1로 끝나야함
		dp[i].first = dp[i - 1].second + dp[i - 1].first;

		// 1로 끝나려면, 앞자리가 0으로 끝나야함
		dp[i].second = dp[i - 1].first;
	}


	cout << dp[n].first + dp[n].second << "\n";
}