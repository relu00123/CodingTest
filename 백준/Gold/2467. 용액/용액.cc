#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	// 산성값 : 1 ~ 1'000'000'000
	// 알칼리값 : -1 ~ -1'000'000'000

	// 두 용액을 혼합하여 특성값이 0에 가장 가까운 용액을 만드려고 한다. 

	// 정렬된 순서로 주어졌을때, 서로 다른 용액을 혼합하여 특성값이 0에 가장 가까운 용액을 만드시오. 
	// 용액의 수는 100'000 개 이하


	// n * log n의 풀이로 풀것임.

	int n; cin >> n;

	vector<int> arr(n);

	for (int i = 0; i < n; ++i)
		cin >> arr[i];

	int ans = 2'000'000'001;
	
	vector<int> answers(2);


	for (auto iter = arr.begin() ; iter != arr.end(); iter++)
	{
		int cur_num = *iter;
		int target = -cur_num;

		

		auto desire = lower_bound(arr.begin(), arr.end(), target);

		if (desire != iter && desire != arr.end())
		{
			if (ans > abs(*iter + *desire))
			{
				ans = abs(*iter + *desire);
				answers[0] = *iter;
				answers[1] = *desire;
			}
		}

		if (desire != arr.begin() && prev(desire) != iter)
		{
			if (ans > abs(*prev(desire) + *iter))
			{
				ans = abs(*prev(desire) + *iter);
				answers[0] = *iter;
				answers[1] = *prev(desire);
			}
		}
	}

	sort(answers.begin(), answers.end());

	cout << answers[0] << " " << answers[1] << "\n";


	return 0;
}