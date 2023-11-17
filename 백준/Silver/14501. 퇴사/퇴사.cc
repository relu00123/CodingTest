#include<bits/stdc++.h>
using namespace std;

int N;

int arr[2][20];
int dp[20];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	for (int i = 1; i <= N; ++i) {
		cin >> arr[0][i] >> arr[1][i];
	}

	for (int i = N; i >= 1; i--) {

		// 임무를 받지 못하는 경우
		if (arr[0][i] + i > N + 1)
			dp[i] = dp[i + 1];

		// 임무를 받을 수 있는 경우 
		else
			dp[i] = max(arr[1][i] + dp[i + arr[0][i]], dp[i + 1]);
		 
	}
	cout << dp[1] << "\n";

	return 0;
}