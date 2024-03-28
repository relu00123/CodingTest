#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
const int max_num = 1e9;
 
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int d[101][101];

	int n, m; cin >> n >> m;

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {

			if (i == j) d[i][j] = 0;
			else d[i][j] = max_num;
		}
	}


	for (int i = 0; i < m; ++i) {
		int v1, v2, c; cin >> v1 >> v2 >> c;
		d[v1][v2] = min(c, d[v1][v2]);
	}


	// 무조건 거쳐야 하는 정점
	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				d[i][j] = min(d[i][k] + d[k][j], d[i][j]);


	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			if (d[i][j] == max_num) cout << "0 ";
			else
				cout << d[i][j] << " ";
		}
		cout << "\n";
	}

	return 0;
}