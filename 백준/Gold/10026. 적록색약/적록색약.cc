#include <bits/stdc++.h>
using namespace std;


char graph[100][100] = {};
bool vis[100][100] = {};
int n;

int count_bfs()
{
	int count = 0;

	queue<tuple<int, int, char>> q = {};

	int dx[4] = { -1, 1, 0, 0 };
	int dy[4] = { 0, 0, 1, -1 };

	// i : 행 , j : 열
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if (vis[i][j] == false)
			{
				vis[i][j] = true;
				q.push({ i, j, graph[i][j]});
				count += 1;

				while (!q.empty())
				{
					auto cur = q.front();
					q.pop();

					vis[get<0>(cur)][get<1>(cur)] = true;

					for (int k = 0; k < 4; ++k)
					{
						int nx = get<0>(cur) + dx[k];
						int ny = get<1>(cur) + dy[k];

						// Range 안에 있는지 확인
						if (0 <= nx && nx < n && ny >= 0 && ny < n)
						{
							// 같은 문자이고 방문한 적이 없다면
							if (graph[nx][ny] == get<2>(cur) && vis[nx][ny] == false)
							{
								vis[nx][ny] = true;
								q.push({ nx, ny, graph[nx][ny] });

							}
						}
					}

				}
			}
		}
	}

	for (int i = 0; i < n; ++i)
	{
		fill(vis[i], vis[i] + n, false);
	}

	return count;
}


int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	// 적록 색양 빨강 - 초록을 합쳐서 봄

	cin >> n;

	// 입력 받음.
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cin >> graph[i][j];
		}
	}

	int normal = count_bfs();
	cout << normal << " ";


	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if (graph[i][j] == 'G')
				graph[i][j] = 'R';
		}
	}

	int disabled = count_bfs();
	cout << disabled << "\n";
	
	return 0;
}