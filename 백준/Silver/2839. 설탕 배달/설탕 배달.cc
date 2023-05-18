#include <bits/stdc++.h>

using namespace std;

int main()
{
	// 무개수 
	int Weight;

	std::cin >> Weight;


	// 확인해야 할 횃수
	int CheckCount;
	CheckCount = Weight / 5;

	for (int i = CheckCount; i >= 0; --i)
	{
		int Remain = Weight - i * 5;

		if (Remain % 3 == 0)
		{
			int Answer = 0;
			Answer += i;
			Answer += Remain / 3;

			cout << Answer << endl;
			return  0;
		}
	}

	cout << -1;
	return 0;

	
}