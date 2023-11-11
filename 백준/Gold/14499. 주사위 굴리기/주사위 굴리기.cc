#include <bits/stdc++.h>
using namespace std; 

int n, m;
int cur_x, cur_y;
int k;
int arr[20][20];
int command;


// 주사위에 대한 정보는 
// 문제애서 주는 전개도를 따름 
int dice[7];

bool isOutside(int _xpos, int _ypos) {
	// 범위 바깥으로 
	if (_xpos < 0 || _xpos >= m || _ypos < 0 || _ypos >= n)
		return true;
	else
		return false;

}


void paint(int _side, int _xpos, int _ypos) {
	if (arr[_ypos][_xpos] == 0) {
		arr[_ypos][_xpos] = dice[_side];
		//dice[_side] = 0;
	}
	else {
		dice[_side] = arr[_ypos][_xpos];
		arr[_ypos][_xpos] = 0;
	}
}


bool rotate(int _dir)
{
	// 동쪽
	if (_dir == 1) {
		int nx = cur_x + 1, ny = cur_y;
		if (!isOutside(nx, ny)) {
			cur_x += 1;
			int temp = dice[3];
			dice[3] = dice[1];
			dice[1] = dice[4];
			dice[4] = dice[6];
			dice[6] = temp;
			paint(6, cur_x, cur_y);
			return true;
		}
	}
	// 서쪽
	else if (_dir == 2) {
		int nx = cur_x - 1; int ny = cur_y;
		if (!isOutside(nx, ny)) {
			cur_x -= 1;
			int temp = dice[4];
			dice[4] = dice[1];
			dice[1] = dice[3];
			dice[3] = dice[6];
			dice[6] = temp;
			paint(6, cur_x, cur_y);
			return true;
		}

	}
	// 북쪽
	else if (_dir == 3) {
		int nx = cur_x , ny = cur_y - 1;
		if (!isOutside(nx, ny)) {
			cur_y -= 1;
			int tmp = dice[5];
			dice[5] = dice[1];
			dice[1] = dice[2];
			dice[2] = dice[6];
			dice[6] = tmp;
			paint(6, cur_x, cur_y);
			return true;
		}
	 

	}
	// 남쪽 
	else if (_dir == 4) {
		int nx = cur_x , ny = cur_y + 1;
		if (!isOutside(nx, ny)) {
			cur_y += 1;
			int tmp = dice[2];
			dice[2] = dice[1];
			dice[1] = dice[5];
			dice[5] = dice[6];
			dice[6] = tmp;
			paint(6, cur_x, cur_y);
			return true;
		}
	}
	return false;
}



int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m >> cur_y >> cur_x >> k;

	for (int i = 0; i < n; ++i) {
		fill(arr[i], arr[i] + 20, -1);
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; ++j) {
			cin >> arr[i][j];
		}
	}


	// 디버깅 용도
	//cout << "\n현재 맵의 모양\n";
	//for (int i = 0; i < n; ++i) {
	//	for (int j = 0; j < m; ++j) {
	//		cout << arr[i][j] << " ";
	//	}
	//	cout << "\n";	
	//}


	while (k--) {
		cin >> command;
		if (rotate(command))
			cout << dice[1] << "\n";

		/*cout << "\n현재 맵의 모양\n";
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				cout << arr[i][j] << " ";
			}
			cout << "\n";
		}*/
	}


}