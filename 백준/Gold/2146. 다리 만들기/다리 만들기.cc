#include <bits/stdc++.h>
using namespace std;

int n;
int origin[100][100];
int bridgetime[100][100];
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };
int color_index = 2;
queue<tuple<int, int, int, int>> border_q; // x, y, color, time 

void color() {
	queue<pair<int, int>> q;

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (origin[i][j] == 1) {
				q.push({ i, j }); 
				origin[i][j] = color_index;

				while (!q.empty()) {
					auto [cur_x, cur_y] = q.front(); q.pop();
					bool isborderland = false;

					for (int dir = 0; dir < 4; ++dir) {
						int nx = cur_x + dx[dir];
						int ny = cur_y + dy[dir];

						if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue; // OOB체크 
						if (origin[nx][ny] == 0)
							isborderland = true;
						if (origin[nx][ny] != 1) continue;
						origin[nx][ny] = origin[cur_x][cur_y];
						q.push({ nx, ny });
					}
					if (isborderland)
						border_q.push({ cur_x, cur_y, origin[cur_x][cur_y], 0});
				}
				color_index++;
			}
		}
	}
}

int calc() {

	int min_ans = 1e9;

	while (!border_q.empty()) {
		auto [cur_x, cur_y, color, time] = border_q.front();
		border_q.pop();

		for (int i = 0; i < 4; ++i) {
			int nx = cur_x + dx[i];
			int ny = cur_y + dy[i];
			if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue; // OOB확인 
			if (origin[nx][ny] == 0 ) // 미개척지일 경우 
			{
				origin[nx][ny] = color;
				bridgetime[nx][ny] = time + 1;

				// 이순간 4개의 방향을 돌려서 다른 종류의 땅과 만나는지 확인한다.
				for (int j = 0; j < 4; ++j) {
					int nnx = nx + dx[j];
					int nny = ny + dy[j];
					if (nnx < 0 || nnx >= n || nny < 0 || nny >= n) continue; // OOB확인 
					if (origin[nnx][nny] != 0 && origin[nnx][nny] != color)
						min_ans = min(min_ans,  time + 1 + bridgetime[nnx][nny]);
				}
				border_q.push({ nx, ny, color, time + 1 });
			}
		}
	}

	return min_ans;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);


	cin >> n;
	for (int i = 0; i < n; ++i) 
		for (int j = 0; j < n; ++j) 
			cin >> origin[i][j];

	color();
	cout << calc() << "\n";
	return 0;
}