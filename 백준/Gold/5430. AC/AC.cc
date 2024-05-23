#include <bits/stdc++.h>
using namespace std;

deque<int> calc(int cnt, string ar) {

	deque<int> q;

	if (ar.size() == 0)
		return q;

	int num = -1;
	for (int i = 1; i < ar.size() - 1; ++i) {
		if (ar[i] == ',') {
			q.push_back(num);
			num = -1;
		}
		else {
			if (num == -1)
				num = (int)(ar[i] - '0');
			else {
				num *= 10;
				num += (int)(ar[i] - '0');
			}
		}
	}

	if (num != -1)
		q.push_back(num);

	return q;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	// R : 배열에 있는 수의 순서를 뒤집는다.
	// D : 첫번째 수를 버리는 함수이다.  배열이 비어있는데 D를 사용한 경우에는 에러가 발생한다. 

	int t; cin >> t; // t는 최대 100개

	while (t--) {
		string order; cin >> order;

		int n; cin >> n;

		// [a,b,c,d, ...] 와 같은 형식으로 배열의 input이 주어진다.
		string arr; cin >> arr;
		 
		deque<int> q = calc(n, arr);

		bool iserror = false;
		bool ispopfront = true;
		for (int i = 0; i < order.size(); ++i) {
			if (order[i] == 'R') {
				ispopfront = !ispopfront;
			}

			else if (order[i] == 'D') {
				if (q.empty()) {
					cout << "error" << "\n";
					iserror = true;
					break;
				}

				else {
					if (ispopfront)
						q.pop_front();
					else
						q.pop_back();
				}
			}
		}

		// 출력
		if (iserror == false) {
			cout << "[";
			if (ispopfront) {
				while (!q.empty()) {
					cout << q.front();
					q.pop_front();

					if (!q.empty())
						cout << ",";
				}
			}
			else {
				while (!q.empty()) {
					cout << q.back();
					q.pop_back();

					if (!q.empty())
						cout << ",";
				}
			}
			cout << "]";
			cout << "\n";
		}
	}


	return 0;
}