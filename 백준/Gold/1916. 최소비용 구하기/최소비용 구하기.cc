#include <bits/stdc++.h>
#include <unordered_map>

#include <array>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	// n개의 도시 , m개의 버스 존재
	// A -> B까지 가는데 드는 비용을 최소화 

	int n, m; cin >> n >> m;

	vector<vector<pair<int, int>>> adj(n + 1);

	for (int i = 0; i < m; ++i) {
		int u, v, c; cin >> u >> v >> c;

		adj[u].push_back({ c, v });
	}

	int st, en; cin >> st >> en;

	const int max_num = 1e9;
	vector<int> dist(n + 1, max_num);

	dist[st] = 0;


	priority_queue<pair<int, int>, vector<pair<int, int>>, std::greater<>> pq;

	pq.push({ 0, st });

	while (!pq.empty()) {
		auto [cur_cost, cur_node] = pq.top(); pq.pop();

		if (dist[cur_node] != cur_cost) continue;

		for (auto [linked_cost, nxt_node] : adj[cur_node]) {
			if (dist[nxt_node] <= dist[cur_node] + linked_cost) continue;
			
			dist[nxt_node] = dist[cur_node] + linked_cost;

			pq.push({ dist[nxt_node], nxt_node });
		}
	}

	cout << dist[en] << "\n";



	return 0;
}