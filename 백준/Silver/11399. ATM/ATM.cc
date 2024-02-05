#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);


	int n;
	cin >> n;


	vector<int> time(n);

	for (int i = 0; i < n; ++i)
	{
		cin >> time[i];
	}

	sort(time.begin(), time.end());

	int ans = 0;

	for (int i = 0; i < n; ++i)
	{
		ans += time[i] * (n - i);
	}


	//for (int i = 0; i < n; ++i)
	//	cout << time[i] << " ";

	//cout << "\n" << ans;

	cout << ans;


	return 0;
}