#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	// 괄호를 적절히 쳐서 식의 값을 최소로 만드는 프로그램을 작성하시오 

	string input; cin >> input; 
	int  ans = 0;

	int temp = 0;
	bool isminusactivated = false; 
	bool nonzerodetected = false;
	for (int i = 0; i < input.size(); ++i)
	{
		if (input[i] == '-')
		{
			if (isminusactivated)
				ans += (-temp);
			else
				ans += temp;

			temp = 0;
			nonzerodetected = false;
			isminusactivated = true;
		}
		else if ( input[i] == '+')
		{
			if (isminusactivated)
				ans += (-temp);
			else
				ans += temp;

			temp = 0; 
			nonzerodetected = false;
		}
		else
		{
			if (input[i] == '0' && nonzerodetected == false) continue;
			else
			{
				nonzerodetected = true;
				temp *= 10;
				temp += (int)(input[i] - '0');
			}
		}
	}

	if (isminusactivated)
		ans += (-temp);
	else
		ans += temp;



	cout << ans << "\n";

	return 0;
}