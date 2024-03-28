#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int find(int x, vector<int>& _p) {
	if (_p[x] < 0) return x;
	return _p[x] = find(_p[x], _p);
}

// 0일시 같은 그룹 1일시 다른 그룹
bool merge(int v1, int v2, vector<int>& _p) {
	v1 = find(v1, _p); v2 = find(v2, _p);

	if (v1 == v2) return false;

	if (_p[v1] == _p[v2]) _p[v1]--;

	if (_p[v1] < _p[v2])
		_p[v2] = v1;
	else
		_p[v1] = v2;
	return true;
}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	// 마을은 N개의 집, 그들을 연결하는 M개의 길로 이루어짐 
	// 마을을 2개로 분리할 것이다. 
	// 각 분리 된 마을안의 집들은 서로 연결되어야 한다.
	// 각 분리된 마을 안에 잇는 임의의 두 집 사이에 경로가 항상 존재해야 한다.

	// 길의 유지비의 합을 최소로 하고 싶다. 

	int n, m; cin >> n >> m;
	 
	                  //v2  c
	vector<vector<pair<int, int>>> adj(n + 1);
	vector<int> p(n + 1);
	fill(p.begin(), p.end(), -1);

	priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;

	for (int i = 0; i < m; ++i) {
		int v1, v2, c; cin >> v1 >> v2 >> c;
		pq.push({ c, v1, v2 });
	}

	int edge_cnt = 0;
	int total_cost = 0;

	while (edge_cnt != n - 1 - 1) {

		auto cur = pq.top(); pq.pop();
		int v1, v2, cost; tie(cost, v1, v2) = cur;

		int p1 = find(v1, p); 
		int p2 = find(v2, p);

		if (p1 == p2) continue;

		merge(p1, p2, p);
		edge_cnt += 1;
		total_cost += cost;
	}

	cout << total_cost << "\n";

	return 0;
}