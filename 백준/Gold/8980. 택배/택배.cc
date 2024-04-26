#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	// 1번마을부터 마지막 마을까지 오른쪽으로 가면서
	// 마을에 있는 물건을 배송한다.
	// 각 마을은 배송할 물건들을 박스에 넣어서 보낸다.
	// 박스를 보내는 마을번호, 박스를 받는 마을번호와 보낼 박스의 개수를 알고 있다. 
	
	// 박스는 받는 마을에서만 내린다.
	// 박스들 중 일부만 배송할 수도 있다. 

	// 마을의 수는 2000 이하의 정수이다. 
	// 용량은 1 이상 10'000 이하
	// 박스 정보는 10'000 개 이하이다. 

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
	//int cur_car[2001];
	map<int, int> cur_car;
	//fill(cur_car, cur_car + 2001, 0);
	int delivered = 0;
	int cur_city = 1;

	while (cur_city <= n) {
		// Step 1 : 하역해야 할 것이 있으면 내린다.
		if (!cur_car.empty()) {
			map<int, int>::iterator iter = cur_car.begin();
			if (iter->first == cur_city) {
				delivered += iter->second;
				cur_capacity -= iter->second;
				cur_car.erase(iter);
			}
		}

		// Step 2 : Capacity에 차지 않을만큼 차에 택배를 싣는다.
		// 또한 더 빨리 배달할 수 있는 도시가 있으면 택배를 바꿔치기한다. 
		map<int, int>::iterator iter = cur_car.begin();
		bool ischangeable = true;
		for (const pair<int, int>& e : info[cur_city]) {
			int next_dest = e.first;
			int sutff_amount = e.second;
			int loadable_amount = c - cur_capacity;

			// 바꾸기만 진행 
			// 택배에 실려있는 도착점이, 지금 도시에서 실을 수 있는 도착점보다 큰 경우 택배를 바꿔치기한다.
			while (ischangeable && iter != cur_car.end()) {
				if (iter->first > next_dest) {
					// 택배에 실려있는 양이 같거나 더 많을 경우
					if (iter->second >= sutff_amount) {
						// 전량 교체한다.
						iter->second -= sutff_amount;
						cur_car[next_dest] = sutff_amount;
						break;
					}

					// 현재 도시에서 보낼 양이 트럭에 실려있는 양보다 더 많은 경우
					else {
						sutff_amount -= iter->second;
						cur_car[next_dest] = iter->second;
						iter = cur_car.erase(iter);
					}
				}
				else {
					ischangeable = false;
					break;
				}
			}

			if (loadable_amount == 0) continue;
			int load_amount = min(sutff_amount, loadable_amount);
			cur_car[next_dest] += load_amount;
			cur_capacity += load_amount;
		}

		// Step 3 : 다음 도시로 차가 이동한다.
		cur_city++;
	}

	std::cout << delivered << "\n";
	return 0;
}