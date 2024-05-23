#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	// 수열 A가 주어졌을때 가장 긴 증가하는 부분수열을 구하는 프로그램을 작성

	int n; cin >> n;

	vector<int> origin(n);
	for (int i = 0; i < n; ++i)
		cin >> origin[i];


	vector<int> ans(n);
	
	
	int last = 0;
	for (int i = 0; i < n; ++i) {
		// i번째 수를 집어넣을 것임

		auto iter = lower_bound(ans.begin(), ans.begin() + last + 1, origin[i]);

		*iter = origin[i];

		if (iter == ans.begin() + last + 1) {
			last++;
		}
	}

	cout << last << "\n";


	return 0;
}