#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> arr;
vector<int> ans;

void back(int _length)
{
	if (_length == m)
	{
		for (int e : ans)
			cout << e << " ";

		cout << "\n";
		return;
	}

	for (int i = 0; i < n; ++i)
	{
		ans.push_back(arr[i]);
		back(_length + 1);
		ans.pop_back();
	}

}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	for (int i = 0; i < n; ++i)
	{
		int temp; cin >> temp; arr.push_back(temp);
	}
	sort(arr.begin(), arr.end());

	back(0);

	return 0;
}