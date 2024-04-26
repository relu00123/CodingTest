#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, c; cin >> n >> c;

	// 보내는 박스의 정보 체우기
	int m; cin >> m;
	vector<vector<pair<int, int>>> info(n + 1);
	while (m--) {
		int st, en, amount; 
		cin >> st >> en >> amount;
		info[st].push_back({ en, amount });
	}

	// 먼저 도착하는 도시가 앞에 있도록 한다.
	for (int i = 1; i <= n; ++i)
		sort(info[i].begin(), info[i].end());

	int cur_capacity = 0;
	int cur_car[2001];
	fill(cur_car, cur_car + 2001, 0);
	int delivered = 0;
	int cur_city = 1;

	while (cur_city <= n) {

		// Step 1 : 하역해야할 물품들 내리기
		int loadable = min(cur_car[cur_city], cur_capacity);
		cur_capacity -= loadable;
		delivered += loadable;

		// Step 2 : 해당 도시 발행의 물품들 적제하기
		const vector<pair<int, int>>& arr = info[cur_city];
		for (const pair<int, int>& e : arr) {
			cur_car[e.first] += e.second;
			cur_capacity = min(c, cur_capacity + e.second);
		}

		// Step3 : 다음 도시로 떠나기
		cur_city++;
	}

	std::cout << delivered << "\n";
	return 0;
}