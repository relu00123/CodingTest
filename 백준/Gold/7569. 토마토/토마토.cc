#include <bits/stdc++.h>
using namespace std;

// M은 가로, N은 세로, H는 높이
int M, N, H;

int graph[100][100][100];
bool visited[100][100][100] = {};

int dx[6] = {0, 0, 1, -1, 0, 0};
int dy[6] = {1, -1, 0, 0, 0, 0};
int dz[6] = {0, 0, 0, 0, 1, -1};

int main()
{
	cin >> M >> N >> H;
	int days = 0;

	// x, y, z위치를 기록할 queue + 몇일차인지
	queue<tuple<int, int, int>> q;

	// 높이
	for (int i = 0; i < H; ++i)
	{
		// 가로
		for (int j = 0; j < N; ++j)
		{
			// 세로
			for (int k = 0; k < M; ++k)
			{
				cin >> graph[j][k][i];

				if (graph[j][k][i] == 1)
				{
					visited[j][k][i] = true;
					q.push({ j, k, i});
				}
			}
		}
	}

	

	while (!q.empty())
	{
		auto cur = q.front();
		q.pop();
	
		for (int dir = 0; dir < 6; ++dir)
		{
			int nx = get<1>(cur) + dx[dir];  // 세로
			int ny = get<0>(cur) + dy[dir];  // 가로
			int nz = get<2>(cur) + dz[dir];

			// Index 범위조건을 만족하는지 확인
			if (0 <= nx && nx < M &&
				0 <= ny && ny < N &&
				0 <= nz && nz < H)
			{
				// 안익은 토마토가 있는지 또 방문하지 않았는지 확인
				if (visited[ny][nx][nz] == false &&
					graph[ny][nx][nz] == 0)
				{
					visited[ny][nx][nz] = true;
					graph[ny][nx][nz] = 
						graph[get<0>(cur)][get<1>(cur)][get<2>(cur)] + 1;

					q.push({ ny, nx, nz });

				}
			}

		}
	}


	// 출력 디버깅
	//cout << "\n";
	//// 높이
	//for (int i = 0; i < H; ++i)
	//{
	//	// 가로
	//	for (int j = 0; j < N; ++j)
	//	{
	//		// 세로
	//		for (int k = 0; k < M; ++k)
	//		{
	//			cout << graph[j][k][i] << " ";
	//		}
	//		cout << "\n";
	//	}
	//	cout << "\n";
	//}


	 //안익은 토마토 있는지 확인, 몇일 걸리는지 확인
	//높이
	for (int i = 0; i < H; ++i)
	{
		// 가로
		for (int j = 0; j < N; ++j)
		{
			// 세로
			for (int k = 0; k < M; ++k)
			{

				// 안익은 토마토가 있는 경우
				if (graph[j][k][i] == 0 && visited[j][k][i] == false)
				{
					//cout << "fail" << "\n";
					cout << -1 << "\n";
					return 0;
				}

				if (graph[j][k][i] >= days)
					days = graph[j][k][i];
				
			}
		}
	}


	cout << days -1 << "\n";
}