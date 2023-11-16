#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> arr;
int n;

int dp[500][500];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;

	// 입력 받기
	for (int i = 0; i < n; ++i) {
		vector<int> newarr;
		
		for (int j = i; j >= 0; j--) {
			int temp;
			cin >> temp;
			newarr.push_back(temp);

			if (i == 0) {
				dp[0][0] = temp;
			}

		}

		arr.push_back(newarr);
	}


	for (int i = 1; i < n; ++i) {
		for (int j = 0; j <= i; ++j) {
			
			// 가장 자리인 경우 선택권이 없음
			if (j == 0) {
				dp[i][j] = dp[i - 1][0] + arr[i][j];
			}
			else if (j == i ) {
				dp[i][j] = dp[i - 1][j - 1] + arr[i][j];
			}	

			else {
				dp[i][j] = max(dp[i - 1][j - 1], dp[i - 1][j]) + arr[i][j];
			}
		}
	}


	auto ans = max_element(dp[n - 1], dp[n-1] + n);

	cout << *ans << "\n";

}