#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	// 지역의 개수 n , 수색범위 m, 길이 개수 r
	int n, m, r; cin >> n >> m >> r;

	int graph[101][101];

	int item_value[101];

	for (int i = 1; i <= n; ++i)
	{
		int value; cin >> value;
		item_value[i] = value;
	}

	// 모든 비용을 최대값으로 초기화 
	for (int i = 1; i <= n; ++i)
		fill(graph[i], graph[i] + n + 1, 200);

	// 자기 자신에 대해서는 초기화
	for (int i = 1; i <= n; ++i)
		graph[i][i] = 0;


	// 길을 이어준다.
	for (int i = 0; i < r; ++i)
	{
		int v1, v2, length;
		cin >> v1 >> v2 >> length;

		graph[v1][v2] = length;
		graph[v2][v1] = length;
	}


	// 플로이드 알고리즘으로 거리 갱신
	for (int k = 1; k <= n; ++k) // k 지역을 무조건 지나가야함
	{
		for (int i = 1; i <= n; ++i)
		{
			for (int j = 1; j <= n; ++j)
			{
				graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
			}
		}
	}


	int max_value = 0;

	for (int i = 1; i <= n; ++i)
	{
		int temp_value = 0;

		// 수색범위는 m임
		for (int k = 1; k <= n; ++k)
		{
			if (graph[i][k] <= m)
				temp_value += item_value[k];
		}

		max_value = max(max_value, temp_value);
	}

	cout << max_value << "\n";

 
	return 0;
}