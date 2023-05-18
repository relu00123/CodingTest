#include <bits/stdc++.h>

using namespace std;

bool compare(const pair<int, int>&  _First, const pair<int, int>& _Second)
{
	 //y좌표가 같지 않은경우 먼저 정렬의 기준이 된다.
	if (_First.second != _Second.second)
	{
		return _First.second < _Second.second;
	}

	// y좌표가 같을시
	else
	{
		return _First.first < _Second.first;
	}

}


int main()
{
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	int N;
	int x, y;
	std::cin >> N;

	vector<pair<int, int>> Buffer;

	for (int i = 1; i <= N; ++i)
	{
		std::cin >> x >> y;

		Buffer.push_back(make_pair(x, y));
	}

	sort(Buffer.begin(), Buffer.end(), compare);

	for (int i = 0; i < N; ++i)
	{
		std::cout << Buffer[i].first << " " << Buffer[i].second << "\n";
	}

	return 0;
}