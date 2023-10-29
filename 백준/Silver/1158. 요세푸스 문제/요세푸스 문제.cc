#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n, k;
	cin >> n >> k;

	list<int> arr = {};
	for (int i = 1; i <= n; ++i)
		arr.push_back(i);

	list<int>::iterator iter = arr.begin();

	std::cout << "<";

	while (arr.size() != 0)
	{ 

		for (int i = 1; i < k; ++i)
		{
 
			iter++;

			if (iter == arr.end())
			{
			 

				iter = arr.begin();
			}
				 
		}

		n--;

		if (n != 0)

			cout << *iter << ", ";

		else
			cout << *iter;
		 
		iter = arr.erase(iter);

		if (iter == arr.end())
			iter = arr.begin();

 
	}

	cout << ">";


	return 0;
}