#include <bits/stdc++.h>
using namespace std;

int main()
{
	int a, b, c;

	std::cin >> a;
	cin >> b;
	cin >> c;

	int result = a * b * c;

	int arr[10] = { 0 ,};

	while (result)
	{
		int number = result % 10;

		arr[number] += 1;

		result /= 10;
	}

	for (int& element : arr)
		cout << element << "\n";

	return 0;
}