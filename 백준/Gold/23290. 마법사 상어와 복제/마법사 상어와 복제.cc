#include <bits/stdc++.h>
using namespace std;

vector<int> arr[4][4];
vector<int> temp_vec[4][4];
bool vis[4][4];
pair<int, int> shark_pos;
int smell_dur[4][4];

deque<pair<int, int>> shark_moved_route;
deque<pair<int, int>> temp_shark_moved_route;

int ate_cnt = 0;
const int max_num = 1e9;
long long int most_ate_num = max_num;

int dy[8] = { -1, -1, 0, 1, 1, 1, 0, -1 };
int dx[8] = { 0, -1, -1, -1, 0, 1, 1, 1 };

// 상 좌 하 우
int ddx[4] = { -1, 0, 1, 0 };
int ddy[4] = { 0, -1, 0, 1 };

void pre_replicate() {
	for (int i = 0; i < 4; ++i)
		for (int j = 0; j < 4; ++j)
			temp_vec[i][j] = arr[i][j];
}

void fish_move() {

	vector<int> moved[4][4];

	for (int i = 0; i < 4; ++i) { // 행
		for (int j = 0; j < 4; ++j) { // 열
			vector<int>& focused_vec = arr[i][j];

			for (int k = 0; k < focused_vec.size(); ++k) {

				bool ismoveable = false;
				for (int cnt = 0; cnt < 8; ++cnt) {
					int next_dir = (focused_vec[k] - cnt + 8) % 8;
					int nx = i + dx[next_dir];
					int ny = j + dy[next_dir];

					if (nx < 0 || nx >= 4 || ny < 0 || ny >= 4) continue; // OOB

					// 상어가 있는 곳이나 냄새가 있는 곳은 지나갈 수 없음
					if (smell_dur[nx][ny] != 0 || (nx == shark_pos.first && ny == shark_pos.second)) continue;

					// 물고기가 다음 위치로 이동
					moved[nx][ny].push_back(next_dir);
					ismoveable = true;

					break;
				}

				if (!ismoveable) // 8방향 모두 움직일 수 없었더라면 이동하지 않는다. 
					moved[i][j].push_back(focused_vec[k]);
			}
		}
	}

	// moved가 물고기가 이동한 위치이므로, arr에 이를 갱신한다.
	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 4; ++j) {
			arr[i][j] = moved[i][j];
		}
	}
}

void shark_move(int shark_x, int shark_y, int moved_cnt, long long int cmp_cnt, int _ate_count, deque<pair<int, int>>& _shark_moved_route) {

	if (moved_cnt == 3)
	{
		if (_ate_count > ate_cnt) {
			ate_cnt = _ate_count;
			most_ate_num = cmp_cnt;
			shark_pos.first = shark_x; shark_pos.second = shark_y;
			shark_moved_route = _shark_moved_route;
		}

		else if (_ate_count == ate_cnt) {
			if (cmp_cnt < most_ate_num)
			{
				ate_cnt = _ate_count;
				most_ate_num = cmp_cnt;
				shark_pos.first = shark_x; shark_pos.second = shark_y;
				shark_moved_route = _shark_moved_route;
			}
		}

		return;
	}


	for (int dir = 0; dir < 4; ++dir) {
		int nx = shark_x + ddx[dir];
		int ny = shark_y + ddy[dir];

		if (nx < 0 || nx >= 4 || ny < 0 || ny >= 4) continue;
		//if (vis[nx][ny] == true) continue;

		 
		// 상은 1, 좌는 2, 하는 3, 우는 4
		_shark_moved_route.push_back({ nx, ny });
		if (vis[nx][ny] == true) {
			shark_move(nx, ny, moved_cnt + 1, cmp_cnt * 10 + dir , _ate_count , _shark_moved_route);
		}
		else {
			vis[nx][ny] = true;
			shark_move(nx, ny, moved_cnt + 1, cmp_cnt * 10 + dir, _ate_count + arr[nx][ny].size(), _shark_moved_route);
			vis[nx][ny] = false;
		}
		_shark_moved_route.pop_back();

		 
	}
}

void reset_for_shark()
{
	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 4; ++j) {
			vis[i][j] = false;
		}
	}

	//vis[shark_pos.first][shark_pos.second] = true;

	ate_cnt = 0;
	most_ate_num = max_num;
	temp_shark_moved_route.clear();
	shark_moved_route.clear();
}

void smell_reduce() {
	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 4; ++j) {
			smell_dur[i][j] = max(0, smell_dur[i][j] - 1);
		}
	}
}

void smell_fill() {
	while (!shark_moved_route.empty()) {
		auto [curx, cury] = shark_moved_route.front(); shark_moved_route.pop_front();
		if (arr[curx][cury].size() != 0)
			smell_dur[curx][cury] = 2;
		arr[curx][cury].clear();
	}
}

void replicate() {
	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 4; ++j) {
			for (int k = 0; k < temp_vec[i][j].size(); ++k) {
				arr[i][j].push_back(temp_vec[i][j][k]);
			}
			temp_vec[i][j].clear();
		}
	}

}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	// m : 물고기의 수, s : 상어가 마법을 연습한 횟수
	int m, s; cin >> m >> s;

	// m개의 줄에는 물고기의 정보 (fx, fy, d) 가 주어진다. 
	// d의 숫자는 1 ~ 8 인데 왼쪽부터 시계방향을 가리킨다.
	// 저장할때는 편의상 0 ~ 7 까지로 저장할 것이다.
	for (int i = 0; i < m; ++i) {
		int x, y, d; cin >> x >> y >> d;
		arr[x - 1][y - 1].push_back(d - 1);
	}

	// 마지막 줄에는 상어의 위치가 주어진다.
	cin >> shark_pos.first >> shark_pos.second;
	shark_pos.first -= 1;
	shark_pos.second -= 1;

	while (s--) {
		// Step 1. 복제마법 시전
		// 반영은 Step5에서 된다. 
		pre_replicate();

		// Step 2. 모든 물고기가 한칸 이동한다.
		fish_move();

		// Step 3. 상어가 연속해서 3칸 이동한다. 
		// 상어 위치 갱신해 줘야 한다.
		reset_for_shark();
		shark_move(shark_pos.first, shark_pos.second, 0, 0, 0, temp_shark_moved_route);


		// Step 4. 두번 전 연습에서 생긴 물고기의 냄새가 격자에서 사라진다. 
		smell_reduce();


		// Step4. 2 상어식사 + 이번 상어의 먹이 섭취로 인한 냄새를 새긴다.
		smell_fill();

		// Step 5. 복제마법이 완료된다. 
		replicate();
	}


	int fish_cnt = 0;

	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 4; ++j) {
			fish_cnt += arr[i][j].size();
		}
	}

	cout << fish_cnt << "\n";

	return 0;
}