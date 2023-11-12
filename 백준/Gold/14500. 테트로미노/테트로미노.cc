#include <bits/stdc++.h>
using namespace std;


int N, M;
int graph[500][500];
int vis[500][500];

int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };
 
int maxcount = 0;

void func(int _stack, int _xpos, int _ypos, int _sum) {

	if (_stack == 4) {
		maxcount = max(maxcount, _sum);
		return;
	}


	if (_xpos < 0 || _xpos >= N || _ypos < 0 || _ypos >= M)
		return;


	int cursum = _sum + graph[_xpos][_ypos];
		

	vis[_xpos][_ypos] = true;

	for (int i = 0; i < 4; ++i) {
		int nx = _xpos + dx[i];
		int ny = _ypos + dy[i];

		if (vis[nx][ny] == false) {
		
			func(_stack + 1, nx, ny, cursum);
		}
	}

	vis[_xpos][_ypos] = false;
}

void specialcase(int _xpos, int _ypos) {
	int support[4] = { 0, 0, 0, 1 };


	do {
		int semisum = 0;
		semisum += graph[_xpos][_ypos];

		for (int i = 0; i < 4; ++i) {
			if (support[i] == 0) {
				int nx = _xpos + dx[i];
				int ny = _ypos + dy[i];

				if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
				semisum += graph[nx][ny];

			}
		}

		maxcount = max(semisum, maxcount);

	} while (next_permutation(support, support + 4));

}


int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M;

	// 입력 받기
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			cin >> graph[i][j];
		}
	}

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			func(0, i, j, 0);
			specialcase(i, j);
		}
	}

	cout << maxcount << "\n";
	return 0;
}