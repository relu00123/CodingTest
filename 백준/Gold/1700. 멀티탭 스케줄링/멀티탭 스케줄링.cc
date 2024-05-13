#include <bits/stdc++.h>
using namespace std;

const int max_num = 1e9;
int cnt = 0;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);


	int n, k; cin >> n >> k;

	vector<int> infos(k);

	for (int i = 0; i < k; ++i) 
		cin >> infos[i];

	unordered_map<int, int> tabs;
	 
	for (int i = 0; i < k; ++i) {  // 100개 

		if (tabs.size() < n) {
			tabs[infos[i]] = max_num;
		}

		else {
			// 현재 꽂은 걸로 해결할 수 있는지 확인.
			if (tabs.find(infos[i]) != tabs.end()) continue;


			// 어떤 것이 가장 마지막에 나오는지 찾아야함. 
			for (int j = i + 1; j < k; ++j) // 100개 
			{
				auto iter = tabs.find(infos[j]);
				if (iter == tabs.end() || iter->second < j) continue;
				iter->second = j;
			}

			int temp_num = 0;
			int target_num = -1;

			// tabs의 값이 가장 큰애를 기억했다가 멀티탭에서 뺀다. 
			// 그리고 tab에 infos[i]를 추가한다.
			for (auto iter = tabs.begin(); iter != tabs.end(); ++iter)
			{
				if (iter->second > temp_num)
				{
					temp_num = iter->second;
					target_num = iter->first;
				}
			}

			tabs.erase(target_num);
			cnt += 1;

			for (auto iter = tabs.begin(); iter != tabs.end(); ++iter) {
				iter->second = max_num;
			}

			tabs[infos[i]] = max_num;
		}

	}

	cout << cnt << "\n";
	

}