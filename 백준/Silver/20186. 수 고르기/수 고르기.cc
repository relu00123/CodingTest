#include <bits/stdc++.h>

using namespace std;

 
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
 

	int n, k; cin >> n >> k;

	vector<int> arr;

	for (int i = 0; i < n; ++i) {
		int temp; cin >> temp; 
		arr.push_back(temp);
	}

	sort(arr.begin(), arr.end());
	reverse(arr.begin(), arr.end());

	int ans = 0;

	for (int i = 0; i < k; ++i) {
		ans += arr[i] - i;
	}

	cout << ans << "\n";


}


	 