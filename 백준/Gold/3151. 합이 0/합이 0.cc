#include <bits/stdc++.h>
using namespace std;
 
int main()
{
	// 세 팀원의 코딩실력이 합이 0이되는 팀을 만드려고 한다.
	// 팀을 얼마나 많이 만들 수 있는지를 계산해라
	// 3인조의 합이 0  이되어야함 
	// 3개의 숫자의 범위는 -10000 <= 범위 <= 10000
	// 3인조의 합이 0이되는 경우의 수를 구하시오
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	long long int cnt = 0;

	vector<int> arr;
	//vector<tuple<int, int, int>> answers;

	for (int i = 0; i < n; ++i)
	{
		int temp;
		cin >> temp;
		arr.push_back(temp);
	}

	sort(arr.begin(), arr.end());

	/*for (int i = 0; i < arr.size(); ++i)
	{
		std::cout << arr[i] << " ";
	}

	cout << "\n=================================\n";*/


	for (int i = 0; i < arr.size(); ++i)
	{
		int target;

		// 배열에서 i번째 index를 제외하고 나머지 두 수의 합이 target이되는 쌍을 전부 찾아야 한다. 

		for (int j = i + 1; j < arr.size(); ++j)
		{
			target = arr[i] + arr[j];

			int count = upper_bound(arr.begin() + j + 1, arr.end(), -target)
			 - lower_bound(arr.begin() + j + 1, arr.end(), -target);

			if (count > 0)
			{
				cnt += count;

				//cout << arr[i] << " " << arr[j] << " " << -target << "\n";
			}
		}
	}

	cout << cnt << "\n";
	
	return 0;
}