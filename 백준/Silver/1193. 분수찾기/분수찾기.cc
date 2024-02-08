#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);


	int x;

	cin >> x;

	int cur_row = 1;
	int cur_col;

	while (true)
	{
		if (x - cur_row > 0)
		{
			x -= cur_row;
			cur_row++;
		}

		else
		{
			cur_col = x;
			break;
		}
	}

	int first;
	int second;


	if (cur_row % 2 == 1)
	{
		// 분자는 작아지고 분모는 커진다.
		first = cur_row - cur_col + 1;
		second = cur_col;
	}

	else
	{
		// 분모는 작아지고 분자는 커진다
		first = cur_col;
		second = cur_row - cur_col + 1;
	}



	cout << first << "/" << second;

	return 0;
}