#include <bits/stdc++.h>
using namespace std;
 

struct element
{
	int s;
	int e;


	bool operator<(const element _other) const {
		return this->s > _other.s;
	}
};


int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);


	int n;
	cin >> n;


	priority_queue<element> stack;

	for (int i = 0; i < n; ++i)
	{
		element newinput;
		cin >> newinput.s;
		cin >> newinput.e;

		stack.push(newinput);
	}


	int ans = 0;
	while (!stack.empty())
	{
		element cur = stack.top(); 
		stack.pop();

		//cout << "cur : " << cur.s << cur.e << "\n";

		while (!stack.empty())
		{
			if (stack.top().s <= cur.e)
			{
				if (stack.top().e >= cur.e)
					cur.e = stack.top().e;
				stack.pop();
			}

			else
			{
				break;
			}
		}

		ans += (cur.e - cur.s);
	}


	cout << ans;

	return 0;
}