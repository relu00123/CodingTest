#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);


	int n; cin >> n;

	vector<int> arr(n);

	for (int i = 0; i < n; ++i)
		cin >> arr[i];

	vector<int> original(arr.begin(), arr.end());

	sort(arr.begin(), arr.end());
	arr.erase(unique(arr.begin(), arr.end()), arr.end());

	map<int, int> answer;
	int idx = 0;
	
	for (int i = 0; i < arr.size(); ++i)
	{
		answer[arr[i]] = idx;
		idx++;
	}


	for (int e : original) {
		cout << answer[e] << " ";
	}
}