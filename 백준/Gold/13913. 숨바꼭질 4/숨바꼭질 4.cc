#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	// 수빈이의 위치 n : 0 <= n <= 100'000
	// 동생의 위치 k : 0 <= n <= 100'000

	// 수빈이 : 걷거나 순간이동 가능
	// 걷기     : 1초후에 x-1 혹은 x+1으로 이동
	// 순간이동  : 1초후에 2*x의 위치로 이동

	// 동생을 찾을 수 있는 가장 빠른 시간을 구하이도

	int n, k; cin >> n >> k;

	// BFS로 접근하면 될 것 같다.
	vector<int> vis(200'000, false);
	vector<int> previous(200'000, 0);

	queue<pair<int, int>> q;

	q.push({n, 0});

	while (!q.empty()) {
		auto[curnum, time] = q.front(); q.pop();

		if (curnum == k) {
			cout << time << "\n";


			int cur = k;

			vector<int> ans;

			ans.push_back(curnum);

			while (cur != n) {
				ans.push_back(previous[cur]);
				cur = previous[cur];
			}

			reverse(ans.begin(), ans.end());

			for (int e : ans)
				cout << e << " ";


			break;
		}


		// 좌측으로 이동
		if (curnum - 1 >= 0 && vis[curnum - 1] == false) {
			vis[curnum - 1] = true;
			previous[curnum - 1] = curnum;
			q.push({ curnum - 1, time + 1 });
		}


		// 우측으로 이동
		if (curnum + 1 < 200'000 && vis[curnum + 1] == false) {
			vis[curnum + 1] = true;
			previous[curnum + 1] = curnum;
			q.push({ curnum + 1, time + 1 });
		}

		
		// 텔레포트
		if (curnum * 2 < 200'000 && vis[curnum * 2] == false) {
			vis[curnum * 2] = true;
			previous[curnum * 2] = curnum;
			q.push({ curnum * 2, time + 1 });
		}


	}
	




	return 0;
}