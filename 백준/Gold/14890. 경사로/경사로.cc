#include <bits/stdc++.h>
using namespace std;

int N, L;

int graph[100][100];
int ans;

// 0일경우 row, 1일경우 col
bool linecheck(int _row_col, int _nth)
{
	bool isused[100];
	fill(isused, isused + 100, false);
	
	// 2번째에서 0일시 왼쪽이 더큼, 1일시 오른쪽이 더큼
	queue<pair<int, int>> fix;

	if (_row_col == 0) {
		for (int i = 0; i < N - 1; ++i) {
			if (graph[_nth][i] != graph[_nth][i + 1]) {
				if (graph[_nth][i] > graph[_nth][i + 1]) 
					fix.push({ i, 0 });
				else
					fix.push({ i, 1 });
			}
		}

		while (!fix.empty()) {
			auto cur = fix.front(); fix.pop();

			int temp = -1;
			// 왼쪽이 더 큰 경우
			if (cur.second == 0) {
				for (int i = cur.first + 1; i <= cur.first + L; ++i) {
					// 인덱스 벗어나면 안됨
					if (i >= N) return false;

					// 사용된 것이면 안됨
					if (isused[i] == true) return false;

					// 단차가 1이상 나면 안됨
					if (abs(graph[_nth][cur.first] - graph[_nth][i]) >= 2) return false;

					// 판때기 놓을곳에서 높이가 다 동일해야함
					if (temp == -1)
						temp = graph[_nth][i];
					else {
						if (temp != graph[_nth][i]) return false;
					}

					isused[i] = true;

				}
			}

			// 오른쪽이 더 큰 경우
			if (cur.second == 1) {
				
				if (cur.first  < 0) return false;
				for (int i = cur.first ; i > cur.first - L; --i) {
					// 인덱스 벗어나면 안됨
					if (i < 0) return false;

					// 사용된 것이면 안됨
					if (isused[i] == true) return false;

					// 단차가 1이나면 안됨
					if (abs(graph[_nth][cur.first] - graph[_nth][cur.first+1]) >= 2) return false;

					// 판때기 놓을 곳에서 높이가 다 동일해야 함
					if (temp == -1)
						temp = graph[_nth][i];
					else {
						if (temp != graph[_nth][i]) return false;
					}

					isused[i] = true;
				}
			}
		}
	}
	else if (_row_col == 1) {
		for (int i = 0; i < N - 1; ++i) {
			if (graph[i][_nth] != graph[i+1][_nth]) {
				if (graph[i][_nth] > graph[i+1][_nth])
					fix.push({ i, 0 });
				else
					fix.push({ i, 1 });
			}
		}

		while (!fix.empty()) {
			auto cur = fix.front(); fix.pop();

			int temp = -1;
			// 왼쪽이 더 큰 경우
			if (cur.second == 0) {
				for (int i = cur.first + 1; i <= cur.first + L; ++i) {
					// 인덱스 벗어나면 안됨
					if (i >= N) return false;

					// 사용된 것이면 안됨
					if (isused[i] == true) return false;

					// 단차가 1이상 나면 안됨
					if (abs(graph[cur.first][_nth] - graph[i][_nth]) >= 2)
						return false;

					// 판때기 놓을곳에서 높이가 다 동일해야함
					if (temp == -1)
						temp = graph[i][_nth];
					else {
						if (temp != graph[i][_nth]) return false;
					}

					isused[i] = true;
				}
			}


			// 오른쪽이 더 큰 경우
			if (cur.second == 1) {

				if (cur.first  < 0) return false;
				for (int i = cur.first ; i > cur.first - L; --i) {
					// 인덱스 벗어나면 안됨
					if (i < 0) return false;

					// 사용된 것이면 안됨
					if (isused[i] == true) return false;

					// 단차가 1이나면 안됨
					if (abs(graph[cur.first][_nth] - graph[cur.first+1][_nth]) >= 2) return false;

					// 판때기 놓을 곳에서 높이가 다 동일해야 함
					if (temp == -1)
						temp = graph[i][_nth];
					else {
						if (temp != graph[i][_nth]) return false;
					}

					isused[i] = true;
				}
			}
		}
	}

	// 0일경우 row 1일경우 col
	//cout << "\n" << _nth << "번째" << _row_col;
	return true;
}

int main(void) {

	cin >> N >> L;

	// 그래프 채우기 
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cin >> graph[i][j];
		}
	}

	for (int i = 0; i < N; ++i) {
		if (linecheck(0, i)) ans += 1;
		if (linecheck(1, i)) ans += 1;
	}

	cout   << ans << "\n";

	return 0;
}