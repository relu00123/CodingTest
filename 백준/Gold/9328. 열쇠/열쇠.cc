#include <bits/stdc++.h>
using namespace std;

int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

// map, posesskeys, isvisit, locked, q
void calc(int _curx, int _cury, vector<string>& _curmap, set<char>& _posesskeys, vector<vector<bool>>& _isvisit,
	unordered_map<char, vector<pair<int, int>>>& _locked, queue<pair<int, int>>& _q, int& _money)
{ 
	char cur_char = _curmap[_curx][_cury];
	if (_isvisit[_curx][_cury] == true)
		return;

	// 빈공간이면 바로 가능
	if (cur_char == '.' ) {
		_isvisit[_curx][_cury] = true;
		_q.push({ _curx, _cury });
	}

	// 돈이 있는 공간이여도 바로 가능,
	else if (cur_char == '$') {
		_isvisit[_curx][_cury] = true;
		_q.push({ _curx, _cury });
		_money += 1;
	}

	// 열쇠가 있는 공간이라면 방문 처리하고 가지고 있는 열쇠 목록에 추가한다.
	// 또한 해당열쇠로 열수 있는 자물쇠를 모두 열어버린다. 
	else if (cur_char >= 'a' && cur_char <= 'z') {
		_isvisit[_curx][_cury] = true;
		char changedkey = cur_char - 'a' + 'A';
		_posesskeys.insert(changedkey);
		_q.push({ _curx, _cury});

		if (_locked.find(changedkey) != _locked.end()) {
			for (pair<int, int>& e : _locked[changedkey]) {
				if (_isvisit[e.first][e.second] != false)  continue;
				_isvisit[e.first][e.second] = true;
				_q.push({ e.first, e.second });
			}
			_locked.erase(changedkey);
		}
	}

	// 열쇠로 열어야 하는 공간인데 열쇠로 열 수 있다면 열고
	// 아직 열쇠로 열수 없다면 _locked에 추가해 놓는다. 
	else if (cur_char >= 'A' && cur_char <= 'Z' ) {
		if (_posesskeys.find(cur_char) != _posesskeys.end())
		{
			_isvisit[_curx][_cury] = true;
			_q.push({ _curx, _cury });
		}
		else
			_locked[cur_char].push_back({ _curx, _cury });
	}
}

 
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t; cin >> t;

	while (t--) {

		int h, w; cin >> h >> w; // h  가 행이고 w가 열

		// . : 빈공간
		// * : 벽, 상근이는 벽을 통과할 수 없음
		// $ : 문서, 상근이가 훔쳐야 하는 것
		// 알파벳 대문자 : 문을 나타낸다
		// 알파벳 소문자 : 열쇠를 나타낸다. 그 문자의 대문자인 모든 물을 열 수 있다. 
		vector<string> map(w);
		for (int i = 0; i < h; ++i) 
			cin >> map[i];
		
		int ans = 0;
		set<char> posesskeys;
		unordered_map<char, vector<pair<int, int>>> locked;
		vector<vector<bool>> isvisit(h, vector<bool>(w, false));

		string originkeys; cin >> originkeys;

		// 마지막 줄에는 이미 가지고 있는 열쇠가 공백없이 주어진다.
		// 만약 열쇠를 하나도 가지고 있지 않으면 0이 주어진다. 
		if (originkeys[0] != '0') {
			for (int i = 0; i < originkeys.size(); ++i)
				posesskeys.insert(originkeys[i] - 'a' + 'A');
		}

		// 처음에 상근이는 빌딩 밖에 있으며, 빌딩 가장자리의 벽이 아닌 곳을 통해 빌딩 안팎을 드나들 수 있다.
		// 코너만 가장자리인 것이 아니라, 모든 가장자리를 뜻하는 것이다.  

		// row, col
		queue<pair<int, int>> q;
		// Step1.
		// 우선 가장자리를 따라 Queue에 집어넣을 수 있는 자리를 모두 집어넣는다.

		// 가장 윗행과 가장 아랫행
		for (int i = 0; i < w; ++i) {
			calc(0, i, map, posesskeys, isvisit, locked, q, ans);
			calc(h - 1, i, map, posesskeys, isvisit, locked, q, ans);
		}

		// 가장 왼쪽열 가장 오른쪽 열  (h가 행, w가 열)
		for (int i = 0; i < h; ++i) {
			calc(i, 0, map, posesskeys, isvisit, locked, q, ans);
			calc(i, w - 1, map, posesskeys, isvisit, locked, q, ans);
		}
		
		// Step2.
		// BFS로 갈 수 있는 곳 방문
		while (!q.empty()) {
			auto [cur_x, cur_y] = q.front(); q.pop();
			for (int dir = 0; dir < 4; ++dir) {
				int nx = cur_x + dx[dir];
				int ny = cur_y + dy[dir];
				if (nx < 0 || nx >= h || ny < 0 || ny >= w) continue; // (h가 행, w가 열)
				if (isvisit[nx][ny]) continue;
				calc(nx, ny, map, posesskeys, isvisit, locked, q, ans);
			}
		}

		cout << ans << "\n";
	}
}