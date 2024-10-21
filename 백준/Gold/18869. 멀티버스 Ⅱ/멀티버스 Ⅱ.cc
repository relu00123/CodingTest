#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);


	// 우주의 개수 m, 우주에 있는 행성의 개수 n
	// m의 크기 100개 이하
	// n의 크기 10'000 이하 

	int m, n; cin >> m >> n;

	vector<vector<int>> universe;
	vector<vector<int>> original(m, vector<int>(n, 0));
	vector<vector<pair<int, int>>> same(m);

	for (int i = 0; i < m; ++i)
	{
		// idx, num
		vector<pair<int, int>> arr(n);
		for (int idx = 0; idx < n; ++idx)
		{
			int temp; cin >> temp;
			arr[idx] = { temp, idx };
			original[i][idx] = temp;
		}

		sort(arr.begin(), arr.end());

		vector<int> temp;
		
		for (int idx = 0; idx < n; ++idx)
		{
			temp.push_back(arr[idx].second);

			if (idx >= 1 && original[i][idx] == original[i][idx - 1])
			{
				same[i].push_back({ idx, idx - 1 });
			}

		}

		universe.push_back(temp);
	}

	int ans_cnt = 0;
	for (int i = 0; i < m; ++i)
	{
		for (int j = i + 1; j < m; ++j)
		{
			if (universe[i] != universe[j]) continue;

			bool is_same = true;
			for (int first = 0; first < same[i].size(); ++first)
			{
				auto cur = same[i][first];
				
				if (original[j][cur.first] != original[j][cur.second])
				{
					is_same = false;
					break;
				}
			}


			for (int second = 0; second < same[j].size(); ++second)
			{
				auto cur = same[j][second];

				if (original[i][cur.first] != original[i][cur.second])
				{
					is_same = false;
					break;
				}
			}


			if (is_same)
				ans_cnt++;
		}
	}

	cout << ans_cnt;

	return 0;
}