#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n; cin >> n;

	vector<vector<int>> adj(n + 1);
	vector<int> dist(n + 1, -1);

	while (true) {
		int v1, v2; cin >> v1 >> v2;
		if (v1 == -1 && v2 == -1) break;

		adj[v1].push_back(v2);
		adj[v2].push_back(v1);
	}

	vector<pair<int, int>> db;

	for (int i = 1; i <= n; ++i) {

		fill(dist.begin(), dist.end(), -1);

		dist[i] = 0;
		queue<int> q; q.push(i);

		while (!q.empty()) {
			int cur = q.front(); q.pop();

			vector<int>& arr = adj[cur];

			for (int j = 0; j < arr.size(); ++j) {
				if (dist[arr[j]] >= 0) continue;
				dist[arr[j]] = dist[cur] + 1;
				q.push(arr[j]);
			}
		}

		int max_num = *max_element(dist.begin(), dist.end());
		db.push_back({ max_num, i });
	}

	sort(db.begin(), db.end());

	int possible_score = db[0].first;
	int cnt = 0;
	vector<int> answers;


	for (int i = 0; i < db.size(); ++i) {
		if (db[i].first != possible_score) break;
		cnt++;
		answers.push_back(db[i].second);
	}

	cout << possible_score << " " << cnt << "\n";
	for (int e : answers)
		cout << e << " ";

	return 0; 
}