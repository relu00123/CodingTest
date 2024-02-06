#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int ans = 0;


	string input;
	cin >> input;

	int arr[50] = { 0, };


	int temp = 0;
	int index = 0;
	bool isminus = false;
	for (int i = 0; i < input.size(); ++i)
	{
		if (input[i] == '+')
		{
			isminus == false ? arr[index] = temp : arr[index] = -temp;
			temp = 0;
			index++;
			isminus = false;
		}
		else if (input[i] == '-')
		{
			isminus == false ? arr[index] = temp : arr[index] = -temp;
			temp = 0;
			index++;
			isminus = true;
		}
		else if (i == input.size() - 1)
		{
			if (isminus == false)
			{
				arr[index] = temp * 10 +(input[i] - '0');
			}
			else if (isminus == true)
			{
				arr[index] =  - (temp * 10 + (input[i] - '0'));
			} 
		}
		else
		{
			temp = temp * 10 + (input[i] - '0');
		}
	}

	/*for (int i = 0; i <= index; ++i)
	{
		cout << arr[i] << " ";
	}*/



	int answer = 0;

	bool isMinusturned = false;
	for (int i = 0; i <= index; ++i)
	{
		if (arr[i] < 0)
			isMinusturned = true;


		if (isMinusturned == false)
		{
			answer += arr[i];
		}
		else
		{
			answer -= abs(arr[i]);
		}
	}

	cout << answer;

	return 0; 
}