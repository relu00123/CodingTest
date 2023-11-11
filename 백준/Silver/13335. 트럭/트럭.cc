#include <bits/stdc++.h>
using namespace std;

// n은 다리를 건너는 트럭의 개수
// w는 다리의 길이
// L은 다리의 최대하중
int n, w, L;
int totaltime;
int remaintruck;
int cur_truck_idx;

// 건너는데 걸리는 시간, 해당 트럭의 무개정보 
list<pair<int, int>> bridge;
int bridge_weight;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> w >> L;

	vector<int> trucks(n);

	remaintruck = n;

	for (int i = 0; i < n; ++i)
		cin >> trucks[i];


	while (remaintruck) {

		// 디버깅
		/*for (auto iter = bridge.begin(); iter != bridge.end(); ++iter) {
			cout << "(" << (*iter).first << " " << (*iter).second << ") ";
		}
		cout << "\n";*/
		


		if (bridge.size() != 0) {
			for (auto iter = bridge.begin(); iter != bridge.end(); ++iter) {
				(*iter).first -= 1;
			}

			auto iter = bridge.begin();
			if ((*iter).first <= 0) {

				bridge_weight -= (*iter).second;
				bridge.erase(iter);
				remaintruck -= 1;
				//totaltime += 1;
				//continue;
			}
			
		}


		if (cur_truck_idx < n && bridge_weight + trucks[cur_truck_idx] <= L) {
			bridge.push_back({ w, trucks[cur_truck_idx] });
			bridge_weight += trucks[cur_truck_idx];
			cur_truck_idx += 1;
		}

		totaltime += 1;
	}

	cout << totaltime << "\n";
}