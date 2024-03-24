#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	// N개의 카드를 가지고 있다. 정수 M이 주어졌을때
	// 이 수가 적혀있는 숫자카드를 몇개 가지고 있는지 출력하시오

	int n; cin >> n;

	vector<int> arr(n);

	for (int i = 0; i < n; ++i)
		cin >> arr[i];

	sort(arr.begin(), arr.end());


	int m; cin >> m;

	for (int i = 0; i < m; ++i) {
		int target; cin >> target;

		int res = 
			upper_bound(arr.begin(), arr.end(), target) - lower_bound(arr.begin(), arr.end(), target);

		cout << res << " ";
	}



	return 0;
}