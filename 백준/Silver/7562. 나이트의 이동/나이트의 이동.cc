#include <bits/stdc++.h>
using namespace std;

int dx[8] = { -2, -1, 1, 2, 2, 1, -1, -2 };
int dy[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };



int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int tc; cin >> tc;

	while (tc--) {

		int len; cin >> len;
		int initx, inity; cin >> initx >> inity;
		int tarx, tary; cin >> tarx >> tary;


		vector<vector<int>> vis(len, vector<int>(len, -1));

		int cnt = 0;

		queue<pair<int, int>> q; 
		q.push({ initx, inity });
		vis[initx][inity] = 0;

		while (!q.empty()) {
			auto cur = q.front(); q.pop();
			
			if (cur.first == tarx && cur.second == tary)
			{
				cout << vis[cur.first][cur.second] << "\n";
				break;
			}

			else
			{
				for (int i = 0; i < 8; ++i)
				{
					int nx = cur.first + dx[i];
					int ny = cur.second + dy[i];

					// OOB 
					if (nx < 0 || nx >= len || ny < 0 || ny >= len) continue;

					// 방문한곳 체크
					if (vis[nx][ny] != -1) continue;
					vis[nx][ny] = vis[cur.first][cur.second] + 1;

					q.push({ nx, ny });
				} 
			}

		}

	





	}



}