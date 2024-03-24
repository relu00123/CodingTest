#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int  n; cin >> n;

	int x = 1;
	while (x * (x + 1) / 2 < n)
		x++;
 
	n = n - ((x - 1) * x / 2);
	 
	bool toggle = true;

	x % 2 == 0 ? toggle = true : toggle = false;

	int up, down;

	if (toggle == true)
	{
		up = 1; down = x;

		while (up != n)
		{
			up += 1;
			down -= 1;
		}
	}

	else  if (toggle == false)
	{
		up = x; down = 1;

		while (down != n)
		{
			down += 1;
			up -= 1;
		}
	}

	 
	cout << up << "/" << down << "\n";
	 



	return 0;
}