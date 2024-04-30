#include <bits/stdc++.h>
using namespace std;

const int max_num = 1e9;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	while (true) {
		int n, m; cin >> n >> m;
		if (n == 0 && m == 0)
			break;

		// n : 장소 ( 0 ~ n-1) 까지 있음
		// m : 도로의 개수 

		int st, en; cin >> st >> en;

		// 일반통행, 도로는 최대 1개가 있음
		// 거의 최단 경로가 없는 경우에는 -1을 출력한다. 

		// cost, next_city, shortest_path
		vector<vector<tuple<int, int, bool>>> adj(n);
		vector<vector<tuple<int, int, bool>>> rev_adj(n);

		while (m--) {
			int v1, v2, cost; cin >> v1 >> v2 >> cost;
			adj[v1].push_back({ cost, v2, false });
			rev_adj[v2].push_back({ cost, v1, false });
		}

		vector<int> dist(n, max_num);
		dist[st] = 0;

		// cost, city 
		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

		const vector<tuple<int, int, bool>>& initial_vec = adj[st];

		for (int i = 0; i < initial_vec.size(); ++i) {
			auto [cur_cost, next_city, is_shortest_path] = initial_vec[i];
			dist[next_city] = cur_cost;
			pq.push({ cur_cost, next_city });
		}

		while (!pq.empty()) {
			auto [cur_cost, cur_city] = pq.top(); pq.pop();

			if (dist[cur_city] != cur_cost) continue;

			const vector<tuple<int, int, bool>>& linked_city = adj[cur_city];

			for (int i = 0; i < linked_city.size(); ++i) {
				auto [cost, next_city, isshortest_path] = linked_city[i];

				if (cur_cost + cost >= dist[next_city]) continue;
				dist[next_city] = cur_cost + cost;
				pq.push({ cur_cost + cost, next_city });
			}
		}

		// 이제 거의 최단 경로를 만들어야 한다. 
		// BFS를 돌려서 최단경로를 전부 체크해준다.

		// cur_city, cost
		queue<pair<int, int>> q;
		//vector<bool> vis(n, false);
		vector<int> rev_dist(n, max_num);
		rev_dist[en] = 0;

		int min_path_length = dist[en];

		// 현재 도시와 현재 도시까지의 거리
		q.push({ en, 0 }); //vis[en] = true;

		while (!q.empty()) {
			auto [cur_city, cur_cost] = q.front(); q.pop();

			vector<tuple<int, int, bool>>& cur_linked = rev_adj[cur_city];

			for (int i = 0; i < cur_linked.size(); ++i) {

				auto [cost, next_city, isshortestpath] = cur_linked[i];

				if (cur_cost + cost + dist[next_city] == min_path_length)
					cur_linked[i] = { cost, next_city, true };

				if (rev_dist[next_city] <= cur_cost + cost) continue;

				rev_dist[next_city] = cur_cost + cost;
				q.push({ next_city, cur_cost + cost });
			}
		}


		// Dijkstra를 한번 더 돌려서 거의 최단 거리를 찾는다.
		fill(rev_dist.begin(), rev_dist.end(), max_num);

		//// cur_cost, cur_city
		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> rev_pq;

		rev_pq.push({ 0, en });
		rev_dist[en] = 0;

		while (!rev_pq.empty()) {
			auto [cur_cost, cur_city] = rev_pq.top(); rev_pq.pop();

			if (rev_dist[cur_city] != cur_cost) continue;

			const vector<tuple<int, int, bool>>& cur_linked = rev_adj[cur_city];

			for (int i = 0; i < cur_linked.size(); ++i) {
				auto [cost, next_city, isshortestpah] = cur_linked[i];

				if (isshortestpah == true) continue; // 최단 경로에 사용되었던 직선은 사용할 수 없음
				if (cur_cost + cost >= rev_dist[next_city]) continue; 

				rev_dist[next_city] = cur_cost + cost;
				rev_pq.push({ cur_cost + cost, next_city });
			}
		}

		if (rev_dist[st] == max_num)
			cout << "-1\n";
		else
			cout << rev_dist[st] << "\n";
	}
	return 0;
}