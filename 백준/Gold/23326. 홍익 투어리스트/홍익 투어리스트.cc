#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);


	// 구역의 개수 : n, 쿼리의 개수 q
	int n, q; cin >> n >> q;

	set<int> places;

	int cur_pos = 0;

	for (int i = 0; i < n; ++i)
	{
		int temp; cin >> temp;
		if (temp == 1)
			places.insert(i);
	}

	while (q--)
	{
		int temp; cin >> temp;

		if (temp == 1)
		{
			int i; cin >> i; 
			i = i - 1;
			auto iter = places.find(i);
			if (iter == places.end())
				places.insert(i);
			else 
				places.erase(iter);
		}
		else if (temp == 2)
		{
			int x; cin >> x;
			cur_pos += x;
			cur_pos = cur_pos % n;
			// 시계 방향으로 x만큼 이동한다.
		}
		else if (temp == 3)
		{
			// 명소에 도달하기 위해 시계 방향으로 몇칸 움직여야 하는가? 
			if (places.size() == 0)
			{
				cout << "-1\n";
				continue;
			}

			else
			{
				auto iter = places.lower_bound(cur_pos);

				if (iter == places.end())
				{
					int nextidx = *(places.begin()) + 1;
					int previdx = n - 1 - cur_pos;
					cout << nextidx + previdx << "\n";
				}

				else
				{
					cout << *iter - cur_pos << "\n";
				}
			}
		}
	}


	return 0;
}