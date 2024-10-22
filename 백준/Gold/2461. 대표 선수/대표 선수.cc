#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
using namespace std;

ll pf_sum[10005];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);


	// 대표로 선발된 보든 학생들 능역치의 최대값과 최솟값의 차이가 
	// 최소로 되도록 프로그램을 작성하이오

	int n, m; cin >> n >> m;

	vector<vector<int>> arr(n, vector<int>(m));

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j)
			cin >> arr[i][j];

		sort(arr[i].begin(), arr[i].end());
	}

	vector<int> idx(n, 0);

	int ans = 2'000'000'000;

	while (true)
	{
		int max_num = 0, max_idx;
		int min_num = 2'000'000'000, min_idx;
		

		for (int i = 0; i < n; ++i)
		{
			if (arr[i][idx[i]] < min_num)
			{
				min_num = arr[i][idx[i]];
				min_idx = i;
			}

			if (arr[i][idx[i]] > max_num)
			{
				max_num = arr[i][idx[i]];
				max_idx = i;
			}
		}

		ans = min(ans, max_num - min_num);
		if (idx[min_idx] == m - 1)
			break;
		idx[min_idx] = idx[min_idx] + 1;
	}

	cout << ans << "\n";


	return 0;
}