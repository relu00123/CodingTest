#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
 

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);


	int n;
	cin >> n;   // n <= 50


	vector<int> minus;
	vector<int> plus;

	bool isZeroin = false;

	for (int i = 0; i < n; ++i)
	{
		int temp;
		cin >> temp;

		if (temp == 0)
		{
			isZeroin = true;
		}

		else if (temp > 0)
		{
			plus.push_back(temp);
		}

		else
		{
			minus.push_back(temp);
		}
	}

	int ans = 0;

	
	// 짝수 먼저처리
	sort(plus.begin(), plus.end(), greater<>());
	 
	// 홀수개가 있을 경우
	if (plus.size() % 2 == 1)
	{
		ans += plus.back();
		plus.pop_back();

		//cout << plus.size(); 
	}

	for (int i = 0; i < ((int)plus.size() - 1) ; i = i + 2)
	{

		if (plus[i] == 1 || plus[i + 1] == 1)
		{
			ans += (plus[i] + plus[i + 1]);
		}
		else
		{
			int temp = plus[i] * plus[i + 1];
			ans += temp;
		}
	}
	
	

	// 홀수 처리
	sort(minus.begin(), minus.end());

	if (minus.size() % 2 == 1)
	{
		if (isZeroin)
		{
			minus.pop_back();
		}
		else
		{
			ans += minus.back();
			minus.pop_back();
		}
	}


	//cout << "minus.size : " << minus.size() << "\n";
	//cout << "minus.size() - 1" << (int)(minus.size()) - 1;

	 

	for (int i = 0 ; i < ((int)minus.size() - 1 ); i = i + 2)
	{
		int temp = minus[i] * minus[i + 1];
		ans += temp;
	}

	cout << ans;

	

	return 0;

}