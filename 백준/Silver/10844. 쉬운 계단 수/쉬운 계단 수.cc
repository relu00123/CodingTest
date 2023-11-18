#include<bits/stdc++.h>
using namespace std;

long long int dp[10][101];
int N;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;


	// N = 1일시
	for (int i = 1; i <= 9; ++i)
		dp[i][1] = 1;

	// N = 2이상일시
	for (int i = 2; i <= N; ++i) {
		for (int j = 0; j <= 9; ++j) {


			if (j == 0) {
				dp[j][i] = dp[j + 1][i -1];
			}

			else if (j == 9) {
				dp[j][i] = dp[j  - 1][i - 1];
			}

			else 
				dp[j][i] = (dp[j - 1][i - 1] + dp[j + 1][i - 1]) % 1000000000;

		}
	}

	long long int sum = 0;
	for (int i = 0; i <= 9; ++i)
		sum = (sum + dp[i][N]) % 1000000000;

	 
	cout << sum << "\n";
}