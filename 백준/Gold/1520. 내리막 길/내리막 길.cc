#include <bits/stdc++.h>
using namespace std;

int dp[500][500];
int arr[500][500];
int n, m;

int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

int calc(int _curx, int _cury) {

	if (_curx == n - 1 && _cury == m - 1)
		return 1;

	if (dp[_curx][_cury] == -1) { // 초행인 경우

		int return_value = 0;

		for (int dir = 0; dir < 4; ++dir) {
			int nx = _curx + dx[dir];
			int ny = _cury + dy[dir];

			if (nx < 0 || nx >= n || ny <0 || ny >= m) continue; // OOB

			if (arr[_curx][_cury] <= arr[nx][ny]) continue;

			return_value += calc(nx, ny);
		}

		dp[_curx][_cury] = return_value;
		return dp[_curx][_cury];
	}

	else { // dfs로 인해 채워진 경우
		return dp[_curx][_cury];
	}

}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	// 내릭막길로만 이동하는 경로의 개수를 구하는 프로그램을 작성하시오
	for (int i = 0; i < 500; ++i) 
		fill(dp[i], dp[i] + 500, -1);

	cin >> n >> m;

	for (int i = 0; i < n; ++i) 
		for (int j = 0; j < m; ++j)
			cin >> arr[i][j];
	
	cout << calc(0, 0) << "\n";
	return 0;
}