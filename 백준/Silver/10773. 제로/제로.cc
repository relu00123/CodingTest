#include <bits/stdc++.h>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int k; cin >> k;

	stack<int> arr;

	while (k--)
	{
		int temp; cin >> temp;

		if (temp == 0)
		{
			if (arr.empty()) continue;

			arr.pop();
		}

		else
		{
			arr.push(temp);
		}
	}

	int sum = 0;

	while (arr.size() != 0)
	{
		int cur = arr.top(); 
		sum += cur;
		arr.pop();
	}

	cout << sum << "\n";


	return 0;
}