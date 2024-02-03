#include <bits/stdc++.h>

using namespace std;

int d[100001];

int main()
{
	int target;

	cin >> target;


	d[1] = 1;
	d[2] = 2;

	for (int i = 3; i <= target; ++i)
	{
		int max_num = sqrt(i);

		int min_count = 9999;

		for (int j = max_num; j >= 1; j--)
		{
			int req =  i - j * j;

			min_count = min(1 + d[req], min_count);
		}

		d[i] = min_count;
	}


	/*for (int i = 1 ; i <= target; ++i)
	{
		cout << d[i] << " ";
	}*/

	// 답줄력
	cout << d[target] << endl;


	return 0;

}