#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n; cin >> n;

	priority_queue<int, vector<int>, std::greater<int>> pq;

	int temp;
	for (int i = 0; i < n * n; ++i)
	{
		cin >> temp; 
		pq.push(temp);

		if (pq.size() > n)
			pq.pop();
	}

	

	cout << pq.top() << "\n";



	return 0;
}