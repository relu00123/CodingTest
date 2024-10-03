#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);


	int n, k; cin >> n >> k;

	list<int> arr;


	for (int i = 1; i <= n; ++i)
	{
		arr.push_back(i);
	}

 

	list<int>::iterator iter = arr.begin();

	std::cout << "<";

	while (arr.size() != 0)
	{
	
		for (int i = 0; i < k - 1; ++i)
		{
			// iterator를 증가시킨다.
			if (next(iter) == arr.end())
			{
				iter = arr.begin();
			}

			else
			{
				iter++;
			}
		}


		// 원소를 삭제한다.
		if (arr.size() != 1)
			std::cout << *iter << ", ";
		else
			std::cout << *iter;
		iter = arr.erase(iter);

		if (iter == arr.end())
			iter = arr.begin();
	}

	std::cout << ">";

	
}