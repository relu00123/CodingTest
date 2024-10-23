#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);


	int n; cin >> n; 

	//                  cost  v1   v2
	priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;


	//vector<vector<int>> graph(n + 1, vector<int>(n + 1, 0));
	int graph[1001][1001];
	vector<bool> vis(1001);
	fill(vis.begin(), vis.end(), false);

	long long int total_cost = 0;
	int total_edge = 0;
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			int cost; cin >> cost;
			graph[i][j] = cost;
		}
	}


	if (n == 1)
	{
		cout << "0" << "\n";
		return 0;
	}


	vis[1] = true; 
	for (int i = 2; i <= n; ++i)
	{
		pq.push({ graph[1][i], 1, i });
	}

	while (true)
	{
		auto cur = pq.top(); pq.pop();

		int cost = get<0>(cur);
		int v1 = get<1>(cur);
		int v2 = get<2>(cur);

		if (vis[v1] == true && vis[v2] == true) continue;

		int added_node;

		if (vis[v1] == false)
		{
			added_node = v1;
			vis[v1] = true;
		}
		else
		{
			added_node = v2;
			vis[v2] = true;
		}

		for (int i = 1; i <= n; ++i)
		{
			if (vis[i] == false && i != added_node)
			{
				pq.push({ graph[added_node][i], added_node, i });
			}
		}

		total_cost += cost;
		total_edge += 1;

		
		if (total_edge == n - 1) break;
	}

	cout << total_cost << "\n";

	return 0;
}