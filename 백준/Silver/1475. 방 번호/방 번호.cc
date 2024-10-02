#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie();

	int n; cin >> n;

	vector<int> arr(9);

	while (n != 0)
	{
		int left = n % 10;
		
		if (left == 9)
			arr[6]++;
		else
		{
			arr[left]++;
		}

		n /= 10;
	}

	if (arr[6] % 2 == 1)
		arr[6] = arr[6] / 2 + 1;
	else
		arr[6] = arr[6] / 2;

	cout << *max_element(arr.begin(), arr.end()) << "\n";


 

	return 0; 
}