#include<bits/stdc++.h>
using namespace std;

int N;

int graph[1001];
int dp[1001];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);


	cin >> N;

	for (int i = 0; i < N; ++i)
		cin >> graph[i];


	fill(dp, dp + N, 1);


	 

	for (int i = 1; i < N; ++i) {
		for (int j = 0; j <= i - 1; ++j) {
			if (graph[j] < graph[i])
				dp[i] = max(dp[i], dp[j] + 1);
		}
	}


	/*for (int i = 0; i < N; ++i)
		cout << dp[i] << " ";

	cout << "\n";*/

	cout << *max_element(dp, dp + N) << "\n";

	return 0;

}