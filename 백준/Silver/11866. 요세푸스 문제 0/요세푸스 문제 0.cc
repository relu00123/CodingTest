#include <bits/stdc++.h>

using namespace std;

int main()
{
	int member, roullete;

	cin >> member >> roullete;

	list<int> Buffer;

	for (int i = 1; i <= member; ++i)
	{
		Buffer.push_back(i);
	}

	list<int>::iterator iter = Buffer.begin();

	int roullete_count = roullete - 1;

	cout << "<";

	while (Buffer.size() != 0)
	{
		while (roullete_count != 0)
		{
			iter++;
			roullete_count -= 1;

			if (iter == Buffer.end())
				iter = Buffer.begin();
		}

		
		cout << *iter;
		if (Buffer.size() != 1)
			cout << ", ";
		iter = Buffer.erase(iter);

		if (iter == Buffer.end())
			iter = Buffer.begin();

		roullete_count = roullete - 1;

	}

	cout << ">";

	return 0;
}