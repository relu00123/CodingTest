#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);


	// 10'000 이하의 수들로 구성된 길이 N짜리 수열이 주어짐
	// 수열에서 연속된 수들의 부분합중에서 그 합이 S이상이 되는 것 중 가장 짧은 것의 길이를 
	// 구하는 프로그램을 작성하시오 



	int ans = 200'000'000;

	int n, s; cin >> n >> s;
	vector<int> a(n); 
	for (int i = 0 ; i < n; ++i)
		cin >> a[i];

	 

	int st = 0, en = 0;
	int sum = a[0];
	if (sum >= s) {
		cout << 1 << "\n";
		return 0 ;
	}

	while (st < n && en < n) {
		if (sum < s) {
			en++; 
			if (en == n)
				break;
			sum += a[en];
		}
		else {
			ans = min(ans, en - st + 1);
			sum -= a[st];
			st++;
			 
		}
	}

	if (ans == 200'000'000)
		cout << "0";
	else
		cout << ans;

	return 0;
}