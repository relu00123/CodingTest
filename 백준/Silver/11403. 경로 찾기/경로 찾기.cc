#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n; cin >> n; 

	vector<vector<int>> adj(n);

	int temp;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> temp;
			if (temp == 1)
				adj[i].push_back(j);
		}
	}


	vector<vector<int>> ans(n, vector<int>(n, 0));




	for (int i = 0; i < n; ++i) {
		queue<int> q;
		q.push(i);

		while (!q.empty())
		{
			int cur = q.front(); q.pop();

			for (int j = 0; j < adj[cur].size(); ++j)
			{

				int linked = adj[cur][j];

				if  ( ans[i][linked] != 1) {
					q.push(linked);
					ans[i][linked] = 1;
				}
			}
		}
	}


	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cout << ans[i][j] << " ";
		}
		cout << "\n";
	}

	return 0;

}