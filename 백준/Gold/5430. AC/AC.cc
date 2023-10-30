#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T;
	cin >> T;

	while (T--)
	{
		string command;
		cin >> command;

		int arrNum = 0;
		cin >> arrNum;

		string arrInput;
		cin >> arrInput;
	
		deque<int> arr = {};

		int index = 0;

		string temp = "";

		if (arrNum != 0)
		{

			while (index != arrInput.size())
			{
				if (arrInput[index] == '[')
				{
					index += 1;
					continue;
				}
				else if (arrInput[index] == ',')
				{
					int result = atoi(temp.c_str());
					arr.push_back(result);
					temp = "";
					index++;
				}
				else if (arrInput[index] == ']')
				{
					int result = atoi(temp.c_str());
					arr.push_back(result);
					temp = "";
					index++;
				}

				else
				{
					temp.push_back(arrInput[index]);
					index++;
				}
			}
		}

		// 출력
		/*for (auto iter = arr.begin(); iter != arr.end(); ++iter)
		{
			cout << *iter << " ";
		}*/

		bool IsBegin = true;
		bool IsError = false;


		for (int i = 0; i < command.size(); ++i)
		{
			if (command[i] == 'R')
			{
				if (IsBegin == true)
					IsBegin = false;
				else
					IsBegin = true;
			}
			else if (command[i] == 'D')
			{
				if (arr.size() == 0)
				{
					IsError = true;
					cout << "error\n";
					break;
				}
				if (IsBegin)
					arr.pop_front();
				else
					arr.pop_back();
			}
		}

		if (IsError)
			continue;

		cout << "[";

		if (IsBegin)
		{
			for (auto iter = arr.begin(); iter != arr.end(); ++iter)
			{
				if (iter == arr.end() - 1)
					cout << *iter;

				else
				{
					cout << *iter << ",";
				}
			}
		}

		else
		{
			for (auto iter = arr.rbegin(); iter != arr.rend(); ++iter)
			{
				if (iter == arr.rend() - 1)
					cout << *iter;

				else
				{
					cout << *iter << ",";
				}
			}
		}

		 


		cout << "]\n";
			
	}
}
