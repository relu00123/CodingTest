#include <bits/stdc++.h>
using namespace std;

int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

const int max_num = 1e9;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	
	// dist, row, col 
	int n; cin >> n;

	vector<list<pair<int, int>>> arr(10);

	vector<vector<int>> graph(n , vector<int>(n ));

	pair<int, int> shark_pos;

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			int temp; cin >> temp;
			graph[i][j] = temp;

			if (temp == 9)
			{
				graph[i][j] = 0;
				shark_pos = { i, j };
			}

			arr[temp].push_back({ i, j });
		}
	}

	int shark_level = 2;
	int shark_exp = 0;
	int moved_cnt = 0;

	while (true) {
		vector<vector<int>> dist(n , vector<int>(n , max_num));

		dist[shark_pos.first][shark_pos.second] = 0;

		// BFS를 통해서 현재 지점부터 모든 지점까지의 거리를 기록한다. 
		queue<pair<int, int>> q; q.push(shark_pos);
		while (!q.empty())
		{
			auto [cur_x, cur_y] = q.front(); q.pop();

			for (int dir = 0; dir < 4; ++dir) {
				int nx = cur_x + dx[dir];
				int ny = cur_y + dy[dir];

				if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
				if (graph[nx][ny] > shark_level || dist[nx][ny] != max_num ) continue; 

				dist[nx][ny] = dist[cur_x][cur_y] + 1;
				q.push({ nx, ny });
			}
		}

		int tar_dist = max_num, tar_row = max_num, tar_col = max_num;
		list<pair<int, int>>::iterator delete_iter;
		int delete_level = max_num;
		bool isfishremain = false;

		int max_shark_level = min(7, shark_level);
		 
		for (int lev = 1; lev < max_shark_level; ++lev) {
			list<pair<int, int>>::iterator iter = arr[lev].begin();

			while (iter != arr[lev].end())
			{
				isfishremain = true;

				if (dist[iter->first][iter->second] < tar_dist)
				{
					tar_dist = dist[iter->first][iter->second];
					tar_row = iter->first; 
					tar_col = iter->second;
					delete_iter = iter;
					delete_level = lev;
				}

				else if (dist[iter->first][iter->second] == tar_dist)
				{
					if (iter->first < tar_row) // 교체
					{
						tar_dist = dist[iter->first][iter->second];
						tar_row = iter->first;
						tar_col = iter->second;
						delete_iter = iter;
						delete_level = lev;
					}

					else if (iter->first == tar_row)
					{
						if (iter->second < tar_col) // 교체 
						{
							tar_dist = dist[iter->first][iter->second];
							tar_row = iter->first;
							tar_col = iter->second;
							delete_iter = iter;
							delete_level = lev;
						}
					}
				}
				iter++;
			}
		}

		if (isfishremain == false)
			break;

		if (tar_row < 0 || tar_row >= n || tar_col < 0 || tar_col >= n || delete_level > 6)
			break;


		if (dist[tar_row][tar_col] == max_num)
			break;

		 
		// 제거해야할 녀석을 찾았음. 

		// 1. 상어위치 갱신 
		shark_pos = { tar_row, tar_col };

		// 2. 움직인 거리 추가
		moved_cnt += dist[tar_row][tar_col];

		// 3. 상어한테 경험치를 먹임 (레벨업할 수 있으면 레벨업도 해야함) 
		shark_exp += 1;

		if (shark_exp >= shark_level) {
			shark_exp = 0;
			shark_level += 1;
		}

		// 4. 먹은 물고기를 없앤다. 
		arr[delete_level].erase(delete_iter);
	}

	cout << moved_cnt << "\n";
	return 0;
}