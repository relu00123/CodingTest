#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);


	int n, l; cin >> n >> l;

	// A1 A2 ... An까지의 수가 주어진다.

	// 값, 들어온 index
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

	for (int idx = 1; idx <= n; idx++) {
		int temp; cin >> temp;
		pq.push({ temp, idx });

		while (pq.top().second < idx - l + 1) {
			pq.pop();
		}

		if (!pq.empty())
			cout << pq.top().first << " ";
		else
			cout << "Something Wrong\n";
	}


	return 0;
}