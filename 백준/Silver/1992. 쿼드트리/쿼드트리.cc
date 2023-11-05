#include <bits/stdc++.h>
using namespace std;

char arr[64][64];
int N;
string r_str;



void recurssion(int _startX, int _startY, int _size)
{
	//r_str += "(";

	bool isDif = false;

	char value = arr[_startX][_startY];

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
		r_str += "(";
		for (int i = 0,  xpos = _startX; i < 2; ++i, xpos += _size / 2)
		{
			for (int j = 0,  ypos = _startY; j < 2; ++j, ypos += _size / 2)
			{
				recurssion(xpos, ypos, _size / 2);
			}
		}
		r_str += ")";
	}


	else
	{
		if (value == '0')
			r_str += "0";
		else if (value == '1')
			r_str += "1";
		 
	}

	//r_str += ")";

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

	cout << r_str << "\n";
	
	return 0;
}