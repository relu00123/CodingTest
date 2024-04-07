#include <bits/stdc++.h>
using namespace std;

const int max_num = 987987987;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	// v개의 마을과  e개의 도로로 구성되어 있는 마을이 있음
	// 도로는 일방통행이다.

	int v, e; cin >> v >> e;

	int graph[402][402];

	for (int i = 1; i <= v; ++i)
	{
		fill(graph[i], graph[i] + v + 1, max_num);
		graph[i][i] = 0;
	}


	// e개의 간선에 대해서 작업을 진행한다.
	while (e--)
	{
		int v1, v2, cost; cin >> v1 >> v2 >> cost;
		graph[v1][v2] = cost;
	}

	
	// 플로이드 알고리즘 
	for (int k = 1; k <= v; ++k)
	{
		for (int i = 1; i <= v; ++i)
		{
			for (int j = 1; j <= v; ++j)
			{
				graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
			}
		}
	}

	int answer = max_num;
	 

	// i번 마을에서 출발 
	for (int i = 1; i <= v; ++i)
	{
		// j 번 마을에 도착
		for (int j = i + 1; j <= v; ++j)
		{
			 

				int cost = graph[i][j] + graph[j][i];
				answer = min(answer, cost);
				 

			 
		}
	}

	if (answer == max_num)
		answer = -1;
	
	cout << answer;



	return 0;
}