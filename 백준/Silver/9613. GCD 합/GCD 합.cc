#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
	while (b != 0) {
		int temp = b;
		b = a % b;
		a = temp;
	}
	return a;
}


int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);


	int T;

	cin >> T;

	 

	while (T--)
	{
		int n;
		long long int ans = 0;

		cin >> n;

		vector<int> arr(n);


		// 입력 받기
		for (int i = 0; i < n; ++i)
		{
			cin >> arr[i];
		}




		for (int i = 0; i < arr.size(); ++i)
		{
			for (int j = i + 1; j < arr.size(); ++j)
			{
				// i와 j의 최대 공약수를 구한다
				int result = gcd(arr[i], arr[j]);

				ans += result;

			}
		}



		cout << ans << "\n";

	}



	return 0;
}