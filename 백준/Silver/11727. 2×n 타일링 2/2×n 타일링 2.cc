#include<bits/stdc++.h>
using namespace std;

long long int dp[1002];

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	dp[1] = 1;
	dp[2] = 3;


	int n;
	cin >> n;

	for (int i = 3; i <= n; ++i) {
		dp[i] = (dp[i - 1] + dp[i - 2] * 2) % 10007;
	}

	cout << dp[n] % 10007 << "\n";

	return 0;
}