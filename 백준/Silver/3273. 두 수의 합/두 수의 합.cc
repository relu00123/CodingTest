#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie();

	int n;
	cin >> n;

	vector<int> arr(n);

	for (int i = 0; i < n; ++i)
		cin >> arr[i];

	int target; cin >> target;

	sort(arr.begin(), arr.end());

	int st = 0, en = arr.size() - 1;

	int cnt = 0;
	while (st < en)
	{
		int sum = arr[st] + arr[en];

		if (sum == target)
		{
			cnt++;
			st += 1;
			en -= 1;
		}

		else if (sum < target)
		{
			st++;
		}
		else if (sum > target)
		{
			en--;
		}
	}

	cout << cnt << "\n";

	return 0;
}