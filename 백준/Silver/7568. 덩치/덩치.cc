#include <bits/stdc++.h>

using namespace std;

bool cmp(pair<int, int> _one, pair<int, int> _second)
{
	return _one.second > _second.second;
}

int main()
{
	// 학생 수
	int n;
	int Weight;
	int Height;

	std::cin >> n;

	int* Ranking = new int[n];



	vector<pair<int, int>> info;

	for (int i = 1; i <= n; ++i)
	{
		std::cin >> Weight;
		std::cin >> Height;

		info.push_back(make_pair(Weight, Height));
	}

	// 키순으로 내림차순 되어 있는 상태
	//sort(info.begin(), info.end(), cmp);

	//for (int i = 0; i < n; ++i)
	//{
	//	std::cout << info[i].first << " " << info[i].second << "\n";
	//}

	int temp_rank = 1;

	for (int i = 0; i < n; ++i)
	{
		temp_rank = 1;

		for (int j = 0; j < n; ++j)
		{
			// 키비교 && 몸무개 비교
			if (info[i].second < info[j].second && info[i].first < info[j].first)
				temp_rank += 1;
		}

		Ranking[i] = temp_rank;
	}

	for (int i = 0; i < n; ++i)
	{
		std::cout << Ranking[i] << " ";
	}

	return 0;
}