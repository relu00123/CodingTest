#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

unordered_map<long long int, long long int> dp;
long long int n, p, q;

long long int find(long long  int _n) {

	if (dp.find(_n) != dp.end())
		return dp[_n];
	else
	{
		dp[_n] = find(_n / p) + find(_n / q);
		return dp[_n];
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> p >> q;
	dp[0] = 1;
	cout << find(n) << "\n";

	return 0;
}