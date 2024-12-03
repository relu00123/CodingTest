#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n; cin >> n; // 건물의 종류 수 N

	// N개의 줄에 걸쳐 각 건물을 짓는데 걸리는 시간, 그 건물을 짓기 위해 먼저 지어져야하는 건물번호가 주어짐 
	// 건물의 번호는 1 ~ N, 각 줄은 -1로 끝난다.
	// N개의 각 건물이 완성되기까지 걸리는 최소 시간을 출력한다. 

	const int max_num = 1e9;

	vector<int> indegree(n + 1, 0);
	vector<int> costs(n + 1, 0);
	vector<vector<int>> adj(n + 1);
	//vector<vector<int>> reverse(n + 1);
	vector<int> dp(n + 1, max_num);

	// cost, node 
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
	//queue<int> q;

	for (int curbuild = 1; curbuild <= n; ++curbuild) {

		int cost; cin >> cost; 
		costs[curbuild] = cost;

		while (true) {
			int prev; cin >> prev; // temp : 선행건물 , i : 현재건물 
			if (prev == -1) break;

			indegree[curbuild] += 1;
			//reverse[i].push_back(temp);
			adj[prev].push_back(curbuild);
		}
	}

	for (int i = 1; i <= n; ++i) {
		if (indegree[i] == 0) {
			//q.push(i);
			pq.push({ costs[i], i});
			dp[i] = min(dp[i], costs[i]);
		}
	}

	while (!pq.empty()) {

		auto [cost, curnode] = pq.top(); pq.pop();

		for (int nxt : adj[curnode]) {
			indegree[nxt] -= 1;
			if (indegree[nxt] == 0) {
				dp[nxt] = min(dp[nxt], dp[curnode] + costs[nxt]);
				pq.push( {dp[nxt], nxt});
			}
		}
	}

	for (int i = 1; i <= n; ++i) {
		cout << dp[i] << "\n";
	}



	return 0;
}