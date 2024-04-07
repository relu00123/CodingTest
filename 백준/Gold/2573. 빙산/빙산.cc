#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };
  
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	// 행과 열에 대한 정보가 들어온다.
	int n, m;  cin >> n >> m;

	vector<vector<int>> graph(n, vector<int>(m, 0));
	for (int i = 0; i < n; ++i) 
		for (int j = 0; j < m; ++j) 
			cin >> graph[i][j];
	
	vector<vector<int>> copy_graph(n, vector<int>(m, 0));
	vector<vector<bool>> vis(n, vector<bool>(m, false));

	int seperateicecount = 0;
	int passed_time = 0;
	while (true) {
		 
		seperateicecount = 0;

		for (int i = 0; i < n; ++i) 
			for (int j = 0; j < m; ++j) 
				copy_graph[i][j] = graph[i][j];

		for (int i = 0; i < n; ++i) 
			fill(vis[i].begin(), vis[i].end(), false);

		 
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				if (graph[i][j] != 0 && vis[i][j] == false) { // 바다가 아니고 방문한적이 없으면 BFS를 돌린다.
					queue<pair<int, int>> q;
					q.push({ i, j });
					vis[i][j] = true;
					seperateicecount += 1;

					while (!q.empty()) {
						auto cur = q.front(); q.pop();

						int surroundice = 0;
						for (int k = 0; k < 4; ++k) {
							int nx = cur.first + dx[k];
							int ny = cur.second + dy[k];

							if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue; 	// OOB 체크
							
							// 주변이 바다인지 체크
							if (graph[nx][ny] == 0)
								surroundice += 1;
							
							if (vis[nx][ny] == false && graph[nx][ny] != 0) {
								q.push({ nx, ny });
								vis[nx][ny] = true;
							}
						}

						copy_graph[cur.first][cur.second] = max(graph[cur.first][cur.second] - surroundice, 0);
					}
				}
			}
		}

		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j)
				graph[i][j] = copy_graph[i][j];
		}

		if (seperateicecount >= 2) {
			cout << passed_time << "\n";
			return 0;
		}

		if (seperateicecount == 0) {
			cout << 0 << "\n";
			return 0;
		}

		passed_time += 1;
	}
	return 0;
}