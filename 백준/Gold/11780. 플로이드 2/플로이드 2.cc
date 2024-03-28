#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
const int max_num = 1e9;
 
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int dist[101][101];
	int nxt[101][101];

	int n; cin >> n;

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			if (i == j) dist[i][j] = 0;
			else dist[i][j] = max_num;
		}
		fill(nxt[i], nxt[i] + 101, 0);
	}

	int m; cin >> m;
	
	for (int i = 0; i < m; ++i) {
		int v1, v2, cost; cin >> v1 >> v2 >> cost;

		if (dist[v1][v2] > cost) {
			dist[v1][v2] = cost;
			nxt[v1][v2] = v2;
		}
	}


	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (dist[i][j] > dist[i][k] + dist[k][j]) {
					dist[i][j] = dist[i][k] + dist[k][j];
					nxt[i][j] = nxt[i][k];
				}
			}
		}
	}

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {

			if (dist[i][j] == max_num)
				cout << "0 ";
			else
				cout << dist[i][j] << " ";
		}
		cout << "\n";
	}

	
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {

			if (i == j) cout << "0\n";
			else if (dist[i][j] == max_num) cout << "0\n";

			else {
				int cnt = 1;

				int cur = i;
				vector<int> paths; paths.push_back(i);
				while (nxt[cur][j] != j) {
					cur = nxt[cur][j];
					paths.push_back(cur);
					cnt += 1;
				}
				paths.push_back(j); cnt += 1;

				cout << cnt << " ";
				for (int e : paths)
					cout << e << " ";
				cout << "\n";
			}



		}
	}




	return 0;
}