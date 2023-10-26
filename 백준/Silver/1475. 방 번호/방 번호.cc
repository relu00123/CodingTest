#include <bits/stdc++.h>
using namespace std;

int main(void)
{
	int n;

	cin >> n;

	int arr[10] = {};

	while (n)
	{
		arr[n % 10] += 1;
		n /= 10;
	}

	int special_case = arr[6] + arr[9];

	// 짝수인경우
	if (special_case % 2)
	{
		arr[6] = special_case / 2 + 1;
		arr[9] = special_case / 2;
	}
	else
	{
		arr[6] = special_case / 2;
		arr[9] = special_case / 2;
	}

	int max = 0;

	for (int i = 0; i <= 9; ++i)

	{
		if (arr[i] > max)
			max = arr[i];
	}

	cout << max << "\n";

	return 0;
}