#include <bits/stdc++.h>
using namespace std;

// 벽은 총 3개를 세워야함
// 0은 빈칸, 1은 벽, 2는 바이러스가 있는 곳

int graph[8][8];
int vis[8][8];
int N, M;

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

#define X first
#define Y second
vector<pair<int, int>> virus;
vector<pair<int, int>> possiblewall;

int ans = -1e9;


void bfs(int _x, int _y, int _arr[8][8]) {
	
	queue<pair<int, int>> q;
	q.push({ _x, _y });
	_arr[_x][_y] = 2;
	vis[_x][_y] = true;


	while (!q.empty()) {
		auto cur = q.front();
		q.pop();

		for (int i = 0; i < 4; ++i) {
			int nx = cur.X + dx[i];
			int ny = cur.Y + dy[i];

			// OOB
			if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;

			 

			if (_arr[nx][ny] == 0 && vis[nx][ny] == false) {
				q.push({ nx, ny });
				_arr[nx][ny] = 2;
				vis[nx][ny] = true;
			}

		}
	}
}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M;

	// 입력 받기
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			cin >> graph[i][j];

			if (graph[i][j] == 2)
				virus.push_back({ i, j });

			else if (graph[i][j] == 0)
				possiblewall.push_back({ i, j });
		}
	}

	vector<int> support(possiblewall.size());
	fill(support.begin(), support.end(), 1);
	support[0] = 0; support[1] = 0; support[2] = 0;

	
	do {

		int copy[8][8];
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < M; ++j) {
				copy[i][j] = graph[i][j];
			}
		}

		for (int i = 0; i < 8; ++i)
			fill(vis[i], vis[i] + 8, false);


		for (int i = 0; i < support.size(); ++i) {
			if (support[i] == 0) {
				copy[possiblewall[i].X][possiblewall[i].Y] = 1;
			}
		}

		// Bfs알고리즘 수행 
		for (int i = 0; i < virus.size(); ++i) {
			bfs(virus[i].X, virus[i].Y, copy);
		}

		int temp_ans = 0;

		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < M; ++j) {
				if (copy[i][j] == 0)
					temp_ans += 1;
			}
		}


		ans = max(ans, temp_ans);


	} while (next_permutation(support.begin(), support.end()));
	 

	cout << ans << "\n";
}