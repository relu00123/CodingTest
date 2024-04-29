#include <bits/stdc++.h>
using namespace std;

// 어떤 사람이 어떤 파티에서는 진실을 듣고 어떤 파티에서는 과장된 이야기를 들었을시
// 거짓말쟁이로 탄로난다.
// 지민이는 모든 파티에 참가.
// 거짓말 할 수 있는 파티의 개수 ? 

int n, m;
int tr_cnt;
vector<int> tr;

vector<bool> vis(51);

int db[51][51];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m; // n은 사람의 수, m은 파티의 수
	cin >> tr_cnt;

	vector<vector<int>> party(m);

	// 진실을 아는 사람 전부 기록
	for (int i = 0; i < tr_cnt; ++i)
	{
		int temp; cin >> temp; tr.push_back(temp);
	}

	// 파티들 전부기록
	for (int i = 0; i < m; ++i)
	{
		int ppl_cnt; cin >> ppl_cnt;

		while (ppl_cnt--)
		{
			int temp; cin >> temp;
			party[i].push_back(temp);
		}

		// db 기록
		for (int j = 0; j < party[i].size(); ++j)
		{
			for (int k = j + 1; k < party[i].size(); ++k)
			{
				int first = party[i][j];
				int second = party[i][k];

				db[first][second] = 1;
				db[second][first] = 1;
			}
		}
	}

	fill(vis.begin(), vis.end(), false);

	// 진실은 tr에 기록되어 있음

	queue<int> q;

	for (int i = 0; i < tr.size(); ++i)
		q.push(tr[i]);

	while (!q.empty())
	{
		int cur = q.front(); q.pop();

		if (vis[cur] == true) continue;
		vis[cur] = true;

		for (int i = 1; i <= n; ++i)
		{
			if (db[cur][i] == 1)
				q.push(i);
		}
	}
	
	int ans_cnt = 0;
	for (int i = 0; i < party.size(); ++i)
	{
		bool canlie = true;

		for (int j = 0; j < party[i].size(); ++j)
		{
			if (vis[party[i][j]] == true)
			{
				canlie = false;
				break;
			}
		}

		if (canlie)
			ans_cnt++;
		
	}

	cout << ans_cnt;

	return 0; 
}