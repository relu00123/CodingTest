#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int E, S, M;

	cin >> E; cin >> S, cin >> M;


	// E 는 15주기
	// S 는 28주기
	// M 은 19주기

	// 최소 공배수는 7980이므로 int의 범위 안에 있음

	for (int i = 1; i <= 8000; i++)
	{
		int first = i % 15;
		if (first == 0)
			first = 15;


		int second = i % 28;
		if (second == 0)
			second = 28;

		int third = i % 19;
		if (third == 0)
			third = 19;

		if (first == E && second == S && third == M)
		{
			cout << i;
			return 0;
		}
	}


	return 0;


}