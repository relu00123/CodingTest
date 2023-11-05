#include <bits/stdc++.h>
using namespace std;

int arr[2187][2187];
int N;
int cnt_0 = 0;
int cnt_1 = 0;
int cnt_m1 = 0;


void recurssion(int _startX, int _startY, int _size)
{
	bool isDif = false;

	int value = arr[_startX][_startY];

	for (int i = _startX; i < _startX + _size; ++i)
	{
		if (isDif)
			break;

		for (int j = _startY; j < _startY + _size; ++j)
		{
			if (isDif)
				break;

			if (arr[i][j] != value)
			{
				// 쪼개야 할 시간 굳이 for문을 다 돌지 않아도 된다.
				isDif = true;
			}
		}
	}

	// 쪼갠다.
	if (isDif)
	{
		for (int i = 0,  xpos = _startX; i < 3; ++i, xpos += _size / 3)
		{
			for (int j = 0,  ypos = _startY; j < 3; ++j, ypos += _size / 3)
			{
				recurssion(xpos, ypos, _size / 3);
			}
		}
	}


	else
	{
		if (value == 0)
			cnt_0 += 1;
		else if (value == 1)
			cnt_1 += 1;
		else if (value == -1)
			cnt_m1 += 1;
	}

}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;

	// 입력받기 
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			cin >> arr[i][j];
		}
	}

	recurssion(0, 0, N);

	cout << cnt_m1 << "\n";
	cout << cnt_0 << "\n";
	cout << cnt_1 << "\n";
	
 

	return 0;
}