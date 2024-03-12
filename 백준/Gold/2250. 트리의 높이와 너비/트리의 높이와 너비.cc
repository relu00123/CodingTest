#include <bits/stdc++.h>
using namespace std;

//  level index
vector<pair<int, int>> db;
int assigned_number = 1;

void in_order(vector<vector<int>>& _db, int _curnode, int _level)
{
	// 왼쪽 자식이 있는지 확인 
	if (_db[_curnode][0] != -1)
	{
		in_order(_db, _db[_curnode][0], _level + 1);
	}

	// 본인에 대해서 확인 
	db.push_back({ _level, assigned_number });
	assigned_number++;

	// 오른쪽 자식이 있는지 확인 
	if (_db[_curnode][1] != -1)
	{
		in_order(_db, _db[_curnode][1], _level + 1);
	}

}



int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	// 같은 레벨(level)에 있는 노드는 같은 행에 위치
	// 한열에는 한 노드만 존재
	// 임의의 노드의 left  subtree는 해당 노드보다 왼쪽 열에 위치
	// 임의의 노드의 right subtree는 해당 노드보다 오른쪽 열에 위치
	// 노드가 배치된 가장 왼쪽 열과 오른쪽 열 사이엔 아무노드도 없이 비어있는 열은 없다. 

	// 너비가 가장 넓은 레벨과 그 레벨의 너비를 출력하는 프로그램을 작성하시오 

	// 해당 노드, 왼쪽 자식, 오른쪽 자식노드 
	// 자식이 없을때는 -1이 주어진다. 
	// 참고로 이진트리임. 

	// 노드의 개수는 10'000개 이하 => 무조건 인접행렬로 풀어야 함 
	int n; cin >> n;

	vector<vector<int>> adj(n + 1);

	// 중위순회를 돌려야함 돌릴때 Level에 대한 정보도 주어야 한다.
	// 이후 (노드의 번호, Level)을 원소가지는 Container에 저장해야함 

	vector<bool> isRoot(n + 1);
	fill(isRoot.begin(), isRoot.end(), true);
	isRoot[0] = false;

	for (int i = 0; i < n; ++i)
	{
		int parent, leftchild, rightchild;
		cin >> parent >> leftchild >> rightchild;

		adj[parent].push_back(leftchild);
		adj[parent].push_back(rightchild);

		if (leftchild != -1)
			isRoot[leftchild] = false;

		if (rightchild != -1)
			isRoot[rightchild] = false;
	}

	int root_idx = 0;
	//int test_cnt = 0;
	for (int i = 1; i <= n; ++i)
	{
		if (isRoot[i] == true)
		{
			root_idx = i;
			//test_cnt++;
			break;
		}
	}


	//db.push_back({ 1, 1});

	// 중위 순회를 돌려버린다. 
	in_order(adj, root_idx, 1);


	// 레벨이랑 번호순으로 정렬되어 있음
	sort(db.begin(), db.end());

	int cur_level = 1;

	int ans_diff = 0;
	pair<int, int> answer;
	for (int i = 0; i < db.size();  )
	{
		// cout << "Level : " << db[i].first << " " << "Value : " << db[i].second << "\n";

		if (db[i].first < cur_level)
			break;

		int biggest = 0, smallest = 10'001;
		while (i < db.size() && db[i].first == cur_level)
		{
			if (db[i].second > biggest)
				biggest = db[i].second;

			if (db[i].second < smallest)
				smallest = db[i].second;
			i++;
		}

		int diff = (biggest - smallest + 1);
		if (diff > ans_diff)
		{
			ans_diff = diff;
			answer.first = cur_level;
			answer.second = ans_diff;
		}

		cur_level++;
	}


	cout << answer.first << " " << answer.second << "\n";

	return 0;
}