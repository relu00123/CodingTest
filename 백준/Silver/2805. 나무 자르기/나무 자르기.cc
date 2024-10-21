#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int tree_cnt, want_woods;
	cin >> tree_cnt >> want_woods;

	vector<int> trees(tree_cnt);

	for (int i = 0; i < tree_cnt; ++i)
		cin >> trees[i];


	// 이분탐색을 통하여 최대한 높은 cut_point를 찾는다.
	int cut_point = 0;

	int st_point = 0, en_point = 1'000'000'000;

	while (st_point <= en_point)
	{
		int mid_point = (st_point + en_point) / 2;

		long long int sum = 0;
		
		for (int i = 0; i < trees.size(); ++i)
		{
			int diff = trees[i] - mid_point;
			if (diff > 0)
				sum += diff;
		}

		if (sum >= want_woods) 
		{
			st_point = mid_point + 1;
			cut_point = max(mid_point, cut_point);
		}

		else // 원하는 만큼의 나무를 얻지 못함 -> 자르는 point를 낮춰야 한다.
		{
			en_point = mid_point - 1;
		}
	}

	cout << cut_point  << "\n";


	return 0;
}