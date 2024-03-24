#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, k; cin >> n >> k;

	vector<bool> isprime(n + 1, true);


	int cnt = 0;
	int answer = 0;
	for (int i = 2; i  <= n; i++)
	{
		if (isprime[i] == false) continue;

		cnt++;
		if (cnt == k) {
			answer = i;
			cout << i << "\n"; return 0;
		}
		 
		for (int j = i * i; j <= n; j += i)
		{
			if (isprime[j] == true)
			{
				isprime[j] = false;
				cnt++;
				if (cnt == k) {
					answer = j;
					cout << j << "\n"; return 0;
						
				}
			}
		} 
	}

	 


	return 0;
}