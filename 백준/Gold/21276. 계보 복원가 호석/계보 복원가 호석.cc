#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	// 몇개의 가문이 존재? 가문의 정보를 출력

	// 석호촌에 살고 있는 사람 n : 1000 이하 
	int n; cin >> n;

	// 인접행렬을 만들어야 한다.

	// 사람이름 번호
	map<string, int> db;
	unordered_map<int, string> db_reverse;
	unordered_map<string, vector<string>> db_child;

	vector<vector<int>> adj(n+1);
	vector<int> indegree(n + 1);
	fill(indegree.begin(), indegree.end(), 0);
	

	// 사람들의 이름이 차례대로 주어짐 (중복 x)
	int _idx = 1;
	for (int i = 0; i < n; ++i)
	{
		string name; cin >> name;
		db[name] = _idx;
		db_reverse[_idx] = name;
		++_idx;
	}


	// 정보의 개수 m 
	int m; cin >> m;

	// X의 조상중에 Y가 있다 
	for (int i = 0; i < m; ++i)
	{
		string X, Y;
		cin >> X >> Y;

		adj[db[Y]].push_back(db[X]);
		indegree[db[X]] += 1;
		//db_child[Y].push_back(X);       // 문제가 되는 코드
	}

	 
	         // fam_num
	vector<int> fam(n + 1);
	fill(fam.begin(), fam.end(), -1);

	int family_idx = 1;
	queue<int> q; 

	vector<string> most_ancestor;

	for (int i = 1; i <= n; ++i)
	{
		if (indegree[i] == 0)
		{
			q.push(i);

			most_ancestor.push_back(db_reverse[i]); // 시간복잡도 별로 안잡아 먹음

			fam[i] = family_idx;
			family_idx++;
		}
	}

	while (!q.empty())
	{
		int cur = q.front(); q.pop();

		for (int e : adj[cur])
		{
			indegree[e] -= 1;
			if (indegree[e] == 0)
			{
				q.push(e);
				fam[e] = fam[cur];

				// 수정부분
				db_child[db_reverse[cur]].push_back(db_reverse[e]);
			}
		}
	}

	for (int i = 1; i <= n; ++i)
	{
		if (fam[i] == -1)
		{
			fam[i] = family_idx;
			family_idx++;
		}
	}

	// 출력

	// 1. 가문의 개수 K를 출력하시오
	cout << family_idx - 1 << "\n";

	// 2. 가문의 시조들의 이름을 공백으로 구분하여 사전순으로 출력하시오
	sort(most_ancestor.begin(), most_ancestor.end());
	for (string e : most_ancestor)
		cout << e << " ";
	cout << "\n";

	// 3 이름의 사전순대로 사람의 이름 | 자식의 수 | 자식들의 이름을 사전순 공백으로 구분하여 출력 
	for (auto iter = db.begin(); iter != db.end(); ++iter)
	{
		cout << iter->first << " ";

		auto it = db_child.find(iter->first);
		if (it == db_child.end())
		{
			cout << "0\n";
		}

		else
		{
			cout << it->second.size() << " ";

			vector<string>& arr_son = it->second;

			sort(arr_son.begin(), arr_son.end());

			for (string s : arr_son)
				cout << s << " ";
			 
			cout << "\n";
		}
	}

	return 0;
}
