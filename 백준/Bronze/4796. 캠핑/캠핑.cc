#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);


	int l, p, v;

	int count = 1;

	while (true)
	{
		int answer = 0;

		cin >> l; cin >> p; cin >> v;

		if (l == 0 && p == 0 && v == 0)
			break;

		int division = v / p;

		answer += division * l;

		if (v - division * p <= l)
		{
			answer += (v - division * p);
		}
		else
		{
			answer += l;
		}

	 

		cout << "Case "<< count << ": "<<  answer << "\n";

		count++;
	}

	 

	return 0;

}
