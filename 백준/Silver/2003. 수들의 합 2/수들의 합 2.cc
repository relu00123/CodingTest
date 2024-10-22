#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);


	// i 부터 j번째 수까지의 합이 M이 되는 경우의 수를 구하는 프로그램을 작성하시오

	int n, m; cin >> n >> m;

	vector<int> arr(n);

	for (int i = 0; i < n; ++i)
		cin >> arr[i];


	int st = 0, en = 1;
	int sum = arr[0];
	int ans_cnt = 0;

	while (st <= en && en <= n)
	{
		if (sum == m)
		{
			sum -= arr[st];
			st++;
			ans_cnt++;
		}

		else if (sum > m)
		{
			sum -= arr[st];
			st++;
		}

		else if (sum < m)
		{
			if (en != n)
				sum += arr[en];
			en++;
		}
	}

	cout << ans_cnt << "\n";


	return 0;
}