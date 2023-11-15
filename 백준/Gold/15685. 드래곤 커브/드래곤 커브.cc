#include <bits/stdc++.h>
using namespace std;


int graph[101][101];
int n;


pair<int, int> nintyshift(pair<int, int> _pivot, pair<int, int> _p1) {
	int newx = _p1.first - _pivot.first;
	int newy = _p1.second - _pivot.second;

	int newxx = -newy + _pivot.first;
	int newyy = newx + _pivot.second;

	return { newxx, newyy };
}



void Dragon(vector<pair<int, int>>& _input, int _nth) {

	if (_nth == 0)
		return;


	pair<int, int> pivot = _input[_input.size() - 1];

	for (int i = _input.size() - 2; i >= 0; i--) {
		pair<int, int> cur = _input[i];

		auto shiftresult = nintyshift(pivot, cur);

		_input.push_back({ shiftresult.first, shiftresult.second });
	}

	Dragon(_input, _nth - 1);
}

bool oob(int _x, int _y) {
	if (_x < 0 || _y < 0 || _x > 100 || _y > 100) return true;
	return false;
}


int main() {
	/*vector<pair<int, int>> test;
	test.push_back({ 0,0 });
	test.push_back({ 1,0 });


	Dragon(test, 3);

	for (int i = 0; i < test.size(); ++i)
		cout << "(" << test[i].first << "," << test[i].second << ") ";*/

	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	while (n--) {

		int xpos, ypos, dir, nth;
		cin >> xpos >> ypos >> dir >> nth;


		vector<pair<int, int>> points;
		points.push_back({ xpos, ypos });


		if (dir == 0) {
			points.push_back({ xpos + 1, ypos });
		}
		else if (dir == 1) {
			points.push_back({ xpos    , ypos - 1});
		}
		else if (dir == 2) {
			points.push_back({ xpos - 1, ypos });
		}
		else if (dir == 3) {
			points.push_back({ xpos    , ypos + 1});
		}

		Dragon(points, nth);


		// 색칠하기 
		for (int i = 0; i < points.size(); ++i) {
			if (points[i].first < 0 || points[i].first > 100 ||
				points[i].second < 0 || points[i].second > 100) continue;

			graph[points[i].first][points[i].second] = 1;
		}
	}


	int cnt = 0;
	// 개수 구하기 
	for (int i = 0; i <= 100; ++i) {
		for (int j = 0; j <= 100; ++j) {

			int temp = 0;
			// 4개의 점이 다 색칠되어 있으면 +1
			if (graph[i][j])  temp += 1;
			if (!oob(i + 1, j)) {
				if (graph[i + 1][j])
					temp += 1;
			}
			if (!oob(i, j + 1)) {
				if (graph[i][j + 1])
					temp += 1;
			}
			if (!oob(i + 1, j + 1)) {
				if (graph[i + 1][j + 1])
					temp += 1;
			}

			if (temp == 4)
				cnt += 1;
		}
	}

	cout << cnt << "\n";



	return 0;
}