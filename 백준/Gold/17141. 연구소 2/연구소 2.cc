#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	// 특정위치에 바이러스 M개를 놓을 것이다.
	// 연구소는 n * n 크기의 정사각형으로 나타낼 수 있다.
	// 0 은 빈칸, 1은 벽, 2는 바이러스를 놓을 수 있는 칸이다.

	// 놓을 수 있는 바이러스의 개수는 10개 이하
	// 한변의 길이는 50이하 
	// 바이러스를 놓을 수 있는 칸의 개수는 10보다 작거나 같은 자연수이다. 

	// 바이러스를 퍼뜨릴 수 있는 최소 시간을 구해보자

	// 정사각형의 한변의 길이 n, 놓을 수 있는 바이러스의 개수 m개
	int n, m; cin >> n >> m;

	vector<vector<int>> graph(n, vector<int>(n, 0));
	vector<vector<pair<int, int>>> copy(n, vector<pair<int, int>>(n, { 0, 0 }));
	vector<pair<int, int>> virus_spot;


	// Graph와 Virus가 있을 수 있는 곳을 다 체운다.
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			int temp; cin >> temp;
			if (temp == 2) {
				virus_spot.push_back({ i, j });
				graph[i][j] = 0;
			}
			else 
				graph[i][j] = temp;
		}
	}

	vector<int> comb_assist(virus_spot.size(), 0);
	for (int i = 0; i < m; ++i)
		comb_assist[i] = 1;
	sort(comb_assist.begin(), comb_assist.end());


	int final_ans = 1e9;
	do {
		// Copy 배열 원본으로 복사
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j)
				copy[i][j] = { graph[i][j], 0 };
	
		queue<tuple<int, int, int>> q;

		// 바이러스 심기
		for (int i = 0; i < comb_assist.size(); ++i) {
			if (comb_assist[i] == 1) {
				int vx = virus_spot[i].first;
				int vy = virus_spot[i].second;
				copy[vx][vy] = {2, 0}; // 바이러스는 2로 표시
				q.push({ vx, vy , 0});  
			}
		}
	 
		while (!q.empty()) {
			auto cur = q.front(); q.pop();
			for (int i = 0; i < 4; ++i) {
				int curx, cury, lasttime; tie(curx, cury, lasttime) = cur;
				int nx = curx + dx[i];
				int ny = cury + dy[i];

				if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue; // OOB Check
				if (copy[nx][ny].first != 0) continue; // 벽이거나 바이러스 있는 경우
				copy[nx][ny].first = 2; copy[nx][ny].second = lasttime + 1;
				q.push({ nx, ny, lasttime + 1});
			} 				
		}

		// 바이러스가 못 퍼진 곳이 있는지 확인
		int passed_time = 0;
		bool virusnotspread = false;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {

				passed_time = max(copy[i][j].second, passed_time);
				if (copy[i][j].first == 0)
					virusnotspread = true;
			}
		}

		if (!virusnotspread)
			final_ans = min(final_ans, passed_time);


	} while (next_permutation(comb_assist.begin(), comb_assist.end()));

	if (final_ans == 1e9)
		final_ans = -1;
	cout << final_ans << "\n";

	return 0;
}