#include <bits/stdc++.h>
using namespace std;

const int max_num = 200'000;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);


	// 도로가 일반통행이다.
	// 왕복시간이 최소가 되는 도시를 구할 것이다.

	// 도시의 개수 N, 도로의 개수 M
	int n, m; cin >> n >> m;


	int graph[201][201];

	for (int i = 1; i <= n; ++i)
		fill(graph[i], graph[i] + n + 1, max_num);

	for (int i = 1; i <= n; ++i)
		graph[i][i] = 0;

	while (m--)
	{
		int v1, v2, cost; cin >> v1 >> v2 >> cost;

		graph[v1][v2] = cost;
	}

	// 친구의 수
	int f; cin >> f;

	// k개만큼 친구들이 살고있는 도시가 주어진다.
	vector<int> homes; 

	for (int i = 0; i < f; ++i)
	{
		int city; cin >> city;
		homes.push_back(city);
	}


	// 플루이드 알고리즘 
	for (int k = 1; k <= n; ++k)
	{
		for (int i = 1; i <= n; ++i)
		{
			for (int j = 1; j <= n; ++j)
			{
				graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
			}
		}
	}


	vector<int> answers;
	int least_num = 1e9;


	// 왕복시간이 가장적은 도시들을 구해보자. 
	// 도시 i를 선택하는 경우
	for (int i = 1; i <= n; ++i)
	{
		int temp_cost = 0;

		bool is_valid = true;

		 
		for (int e : homes)
		{
			if (graph[e][i] != max_num && graph[i][e] != max_num)
			{
				temp_cost =  max(temp_cost,  (graph[e][i] + graph[i][e]));
			}

			else
			{
				is_valid = false;
				break;
			}
		}

		if (is_valid)
		{
			if (temp_cost == least_num)
			{
				answers.push_back(i);
			}
			else if (temp_cost < least_num)
			{
				answers.clear();
				answers.push_back(i);
				least_num = temp_cost;
			}
		}
	}


	for (int i = 0; i < answers.size(); ++i)
		cout << answers[i] << " ";

	return 0;

}