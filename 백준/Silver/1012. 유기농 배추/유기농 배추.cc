#include <bits/stdc++.h>
using namespace std;

int graph[51][51];
bool vis[51][51];

int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };


int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t; cin >> t; 

	while (t--)
	{
		int m, n, k; cin >> n >> m >> k;
		int answer_cnt = 0;

		for (int i = 0; i < 51; ++i)
		{
			fill(vis[i], vis[i] + 51, false);
			fill(graph[i], graph[i] + 51, 0);
		}

		while (k--)
		{
			int row, col; cin >> row >> col;
			graph[row][col] = 1;
		}

		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < m; ++j)
			{
				if (vis[i][j] == true || graph[i][j] == 0) continue;
				
				vis[i][j] = true;
				answer_cnt += 1;

				queue<pair<int, int>> q;
				q.push({ i, j });


				while (!q.empty())
				{
					auto cur = q.front(); q.pop();
					int curx = cur.first, cury = cur.second;

					for (int idx = 0; idx < 4; ++idx)
					{
						int nx = curx + dx[idx];
						int ny = cury + dy[idx];

						if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
						if (vis[nx][ny] == true) continue;  
						if (graph[nx][ny] == 0) continue;   

						vis[nx][ny] = true;
						q.push({ nx, ny });
					}
				}
			}
		}
		
		cout << answer_cnt << "\n";
	}

	return 0;
}