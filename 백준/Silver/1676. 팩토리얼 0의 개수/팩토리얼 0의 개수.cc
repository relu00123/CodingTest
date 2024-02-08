#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);


	int n; 
	cin >> n;

	int ans = 0;


	for (int i = 1; i <= n; ++i)
	{

		int temp = i;

		while (temp % 5 == 0)
		{
			temp = temp / 5;
			ans += 1;
		}

	}

	cout << ans;

	return 0;
}