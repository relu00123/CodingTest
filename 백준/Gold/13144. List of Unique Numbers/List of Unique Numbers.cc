#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	// 길이가 n인 수열이 주어질때
	// 수열에서 연속한 1개이상의 수를 뽑았을때, 같은 수가 여러번 등장하지 않는 경우의 수를 
	// 구하는 프로그램을 작성

	int n;
	cin >> n;

	vector<int> arr(n);
	for (int i = 0; i < n; ++i)
		cin >> arr[i];

	set<int> s;
	long long int ans = 0;

	for (int i = 0; i < n; ++i) {

		if (s.empty())
			s.insert(arr[i]);


		while (i + s.size() < n) {
			if (s.find(arr[i + s.size()]) == s.end()) {
				s.insert(arr[i + s.size()]);
			}
			else {
				break;
			}
		}

		ans += s.size();

		s.erase(s.find(arr[i])); // 다음 index로 넘어가려면 혀재수는 지워야 한다. 
	}


	cout << ans << "\n";


	return 0;
}