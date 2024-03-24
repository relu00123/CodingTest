#include <bits/stdc++.h>
using namespace std;

const int max_num = 123457 * 2;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n; cin >> n;

	vector<int> arr(n);

	for (int i = 0; i < n; ++i)
		cin >> arr[i];

	sort(arr.begin(), arr.end());


	int m; cin >> m;

	for (int i = 0; i < m; ++i)
	{
		int target; cin >> target;
		cout << binary_search(arr.begin(), arr.end(), target) << "\n";
 	}



	return 0;
}