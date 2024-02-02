#include <bits/stdc++.h>

using namespace std;

int main()
{
	string s1, s2;

	cin >> s1; cin >> s2;


	vector<vector<int>> graph(s1.size(), vector<int>(s2.size(), 0));

	if (s1[0] == s2[0])
	{
		graph[0][0] = 1;
	}
	else
	{
		graph[0][0] = 0;
	}



	for (int col = 0; col < s2.size(); ++col)
	{
		for (int row = 0; row < s1.size(); ++row)
		{
			if (s1[row] == s2[col])
			{
				if (row - 1 >= 0 && col - 1 >= 0)
					graph[row][col] = graph[row - 1][col - 1] + 1;
				else
					graph[row][col] = 1;
			}


			else
			{
				if (row - 1 >= 0 && col - 1 >= 0)
					graph[row][col] = max(graph[row - 1][col], graph[row][col - 1]);

				else if (row - 1 >= 0)
					graph[row][col] = graph[row - 1][col];
				else if (col - 1 >= 0)
					graph[row][col] = graph[row][col - 1];

				else if (row == 0 && col == 0 )
				{
			
				}
				else
				{
					cout << "something wrong happened!" << "\n";
					cout << "row : " << row;
					cout << "col : " << col;
				}
			}
		}
	}


	// Debugging
	/*for (int col = 0; col < s2.size(); ++col)
	{
		for (int row = 0; row < s1.size(); ++row)
		{
			cout << graph[row][col];
		}
		cout << "\n";
	}*/

	cout << graph[s1.size() - 1][s2.size() - 1];

	return 0;

 
}