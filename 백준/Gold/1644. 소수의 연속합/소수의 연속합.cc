#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);


	// 자연수가 주어졌을때, 이 자연수를 연속된 소수의 합으로 나타낼 수 있는
	// 경우의 수를 판단하시오


	int n; cin >> n; // n <= 4'000'

	if (n == 1)
	{
		cout << 0 << "\n";
		return 0;
	}

	// 1. 에라토스테네스의 채로 4'000'000 까지의 소수를 구하자.

	vector<int> primes;

	vector<bool> num(n + 1, true);
	
	num[0] = false;
	num[1] = false;

	for (long long int i = 2; i <= n; ++i)
	{
		if (num[i] == false) continue;
		primes.push_back(i);
		for (long long int j = i * i; j <= n; j += i)
		{
			num[j] = false;
		}
	}

	// 일단 소수들 잘 구해졌는지 확인
	//for (int i = 0; i < primes.size(); ++i)
	//	cout << primes[i] << " ";

	int st = 0, en = 1;
	int sum = 2;
	int cnt = 0;

	do
	{
		if (sum == n)
		{
			sum -= primes[st];
			st++;
			cnt++;
			continue;
		}

		else if (sum < n)
		{
			if (en <= primes.size() - 1)
				sum += primes[en];
			en++;
			continue;
		}

		else if (sum > n)
		{
			sum -= primes[st];
			st++;

			if (st > en) break;
			continue;
		}
	} while (st <= en && en <= primes.size());

	cout << cnt << "\n";






	return 0;
}