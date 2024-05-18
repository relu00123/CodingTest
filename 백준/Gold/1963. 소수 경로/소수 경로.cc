#include <bits/stdc++.h>
using namespace std;

const int max_num = 1e9;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	// 입력은 항상 네 자리 소수만 주어진다고 가정하자. 
	// 소수 A 에서 B로 바꾸는 과정에서도 항상 네 자리 소수임을 유지해야 한다. 
	// 1000미만의 비밀번호는 허용되지 않는다. 

	vector<bool> isPrime(10000, true);

	isPrime[0] = false;
	isPrime[1] = false;

	for (int i = 2; i * i < 10000; ++i) {

		if (isPrime[i] == false) continue;

		for (int j = i * i; j < 10000; j += i) {
			isPrime[j] = false;
		}
	}

 
	int n; cin >> n;

	// Testcase n번에 걸쳐서 할 것임.
	for (int i = 0; i < n; ++i) {
	
		// key : 소수 , data : 몇번만에 소수로 만들 수 있는지. 
		unordered_map<string, int> db;


		for (int i = 1000; i < 10000; ++i)
		{
			if (isPrime[i] == true)
				db[to_string(i)] = max_num;
		}


		int st, en; cin >> st >> en;

		db[to_string(st)] = 0;
		queue<pair<string, int>> q;
		q.push({ to_string(st), 0 });

		while (!q.empty()) {
			auto [cur, num] = q.front(); q.pop();

			if (db[cur] != num) continue;

			// 4자리수를 모두 바꿀 수 있다.
			for (int idx = 0; idx < 4; ++idx) {

				int start_num = 0;
				if (idx == 0)
					start_num = 1;

				for ( ; start_num <= 9; ++start_num) {
					string tempcur = cur;
					tempcur[idx] = ('0' + start_num);

					if (db[tempcur] <= num + 1) continue;
					db[tempcur] = num + 1;
					q.push({ tempcur, num + 1 });
				}
			}
		}

		if (db[to_string(en)] == max_num)
			cout << "Impossible\n";
		else
			cout << db[to_string(en)] << "\n";
	}

	

}