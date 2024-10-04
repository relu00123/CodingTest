#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	 

	int n; cin >> n;
	int ans_cnt = 0;

	while (n--)
	{

		string str;
		cin >> str;

		stack<char> s;

		bool ispossible = true;


		for (int i = 0; i < str.size(); ++i)
		{
			char temp = str[i];

			if (s.empty()) {
				s.push(temp);
			}

			else {
				if (s.top() == temp) {
					s.pop();
				}


				else {
					s.push(temp);
				}
			}
		}

		if (s.empty() && ispossible)
			ans_cnt += 1;

	}

	cout << ans_cnt << "\n";


	return 0;
}