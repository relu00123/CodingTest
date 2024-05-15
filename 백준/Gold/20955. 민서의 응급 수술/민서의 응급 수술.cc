#include <bits/stdc++.h>
using namespace std;

int find(int x, vector<int>& _parent) {
	if (_parent[x] < 0)
		return x;

	return _parent[x] = find(_parent[x], _parent);
}

bool merge(int v1, int v2, vector<int>& _parent) {
	v1 = find(v1, _parent);
	v2 = find(v2, _parent);

	if (v1 == v2) return false;

	if (_parent[v1] == _parent[v2])
		_parent[v1] -= 1;
	if (_parent[v1] < _parent[v2])
		_parent[v2] = v1;
	else
		_parent[v1] = v2;
	return true;
}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	// 일부 시냅스 연결이 끊어짐.
	// 모든 뉴런을 하나의 트리 형태로 연결해 보고자 한다.
	// 연결되지 않은 두 뉴런을 연결하거나 이미 연결된 두 뉴련의 연결을 끊는다.

	// 하나의 트리 형태로 연결하기 위해 필요한 최소 연산횟수


	// 최소 신장트리의 개수들 - 1 의 연산만큼 덧셈이 필요하다.
	// 노드의 개수가 a개인 트리를 만들면 간선의 개수는 a - 1개이다.
	// 즉, a개의 노드의 모든 간선의 개수를 더하고 2로나눈다음에 a -1을 빼면 잘라야 하는 시냅스의 개수

	// 노드의 개수 : n, 간선의 개수 m
	int n, m; cin >> n >> m;


	vector<vector<int>> adj(n + 1); // 모든 간선의 정보를 받아 넣음
	for (int i = 0; i < m; ++i) {
		int v1, v2; cin >> v1 >> v2;
		adj[v1].push_back(v2);
		adj[v2].push_back(v1);
	}

	vector<int> parent(n + 1, -1);

	vector<bool> isused(n + 1, false);
	int root_count = 0;

	unordered_map<int, int> db;

	for (int i = 1; i <= n; ++i) {
		if (isused[i] == true) continue;
		isused[i] = true;
		root_count += 1;
		db[i] = adj[i].size();

		queue<int> q; q.push(i);

		while (!q.empty()) {
			int cur_node = q.front(); q.pop();

			vector<int>& linked = adj[cur_node];
			for (int j = 0; j < linked.size(); ++j)
			{
				if (!merge(i, linked[j], parent)) continue;
				q.push(linked[j]);
				isused[linked[j]] = true;
				db[i] += adj[linked[j]].size();
			}
		}
	}


	/*cout << root_count << "\n";

	for (int i = 1; i <= n; ++i)
		cout << find(i, parent) << " ";

	cout << "\n";

	for (auto iter = db.begin(); iter != db.end(); ++iter) {
		iter->second = iter->second / 2;
	}

	cout << "===========\n";*/

	 
	cout << m - n + (2 * root_count) - 1 << "\n";
	

	return 0;
}