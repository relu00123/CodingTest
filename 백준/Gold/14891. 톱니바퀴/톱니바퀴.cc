#include <bits/stdc++.h>
using namespace std; 


vector<list<char>> topni(4);
int k;
int topni_num, rotate_dir;

// 0일경우 움직이지 않음, 1일경우 시계방향, -1일 경우 오른쪽 방향
int record[4]{ 0, 0, 0, 0 };

char get_nth_value(int _nth_topni, int _nth_value)
{
	auto iter = topni[_nth_topni].begin();

	while (_nth_value--)
		iter++;

	char temp = (*iter);

	
	return (*iter);
}


// dir이 true인 경우 시계방향, false인경우 반시계 방향
void rotate(int _force, int _cur, bool _dir) {
	if (_cur >= 4 || _cur < 0)
		return;

	// 왼쪽 톱니가 오른쪽 톱니를 움직이려고 하는 경우
	if (_force < _cur) {
		// 다를 경우 회전한다.
		if (get_nth_value(_force, 2) != get_nth_value(_cur, 6)) {
			
			// _cur 톱니에 대한 회전
			// 시계 방향
			if (_dir == true)
				record[_cur] = 1;
			// 반시계 방향
			else if (_dir == false)
				record[_cur] = -1;

			// 연쇄적인 톱니의 회전
			rotate(_cur, _cur + 1, !_dir);
		}
	}

	// 오른쪽 톱니가 왼쪽 톱니를 움직이려고 하는 경우
	else if (_force > _cur) {
		// 다를 경우 회전 한다.
		if (get_nth_value(_force, 6) != get_nth_value(_cur, 2)) {

			// _cur 톱니에 대한 회전
			// 시계 방향
			if (_dir == true)
				record[_cur] = 1;
			// 반시계 방향
			else if (_dir == false)
				record[_cur] = -1;

			// 연쇄적인 톱니의 회전
			rotate(_cur, _cur - 1, !_dir);
		}
	}
}

int main() {
	// 모든 톱니에 대한 입력을 받음
	// 0번 인덱스가 12시 방향. 시계방향 순서대로 값이 주어진다.
	for (int i = 0; i < 4; ++i) {
		string temp;
		cin >> temp;

		for (int j = 0; j < temp.size(); ++j)
			topni[i].push_back(temp[j]);
	}

	// 회전 횟수가 주어짐
	cin >> k;

	while (k--) {
		// 1인 경우 시계방향 
		// -1인 경우 반시계 방향 

		cin >> topni_num >> rotate_dir;
		topni_num -= 1;


		 
		if (rotate_dir == 1) {
			rotate(topni_num, topni_num + 1, false);
			rotate(topni_num, topni_num - 1, false);
			record[topni_num] = 1;
		}

		else if (rotate_dir == -1) {

			rotate(topni_num, topni_num + 1, true);
			rotate(topni_num, topni_num - 1, true);
			record[topni_num] = -1;
		}



		// 디버깅용도
		//for (int i = 0; i < 4; ++i)
		//	cout << i << "번째 톱니 :" << record[i] << "\n";


		// 실제 회전
		for (int i = 0; i < 4; ++i)
		{
			// 반시계 방향 회전인 경우
			if (record[i] == -1) {
				char top = topni[i].front();
				topni[i].pop_front();
				topni[i].push_back(top);

			}

			else if (record[i] == 1) {
				char end = topni[i].back();
				topni[i].pop_back();
				topni[i].push_front(end);
			}
		}

		fill(record, record + 4, 0);

		// 디버깅용도
	/*	for (int i = 0; i < 4; ++i) {

			cout << "i번째 톱니 : ";

			for (auto iter = topni[i].begin();
				iter != topni[i].end(); ++iter) {
				cout << (*iter) << " ";
			}
			cout << "\n";
		}*/
	}


	// N극은 0이고 S극은 1이다.
	int ans = 0;
	get_nth_value(0, 0) == '0' ? ans += 0 : ans += 1;
	get_nth_value(1, 0) == '0' ? ans += 0 : ans += 2;
	get_nth_value(2, 0) == '0' ? ans += 0 : ans += 4;
	get_nth_value(3, 0) == '0' ? ans += 0 : ans += 8;


	cout << ans << "\n";

	return 0;
}