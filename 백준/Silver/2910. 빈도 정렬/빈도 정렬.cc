#include<bits/stdc++.h>
using namespace std;

int N, C;

bool cmp(tuple<int, int, int> _e1, tuple<int, int, int> _e2) {

	// 발생빈도가 같다면
	if (get<1>(_e1) == get<1>(_e2)) {

		// 들어온 순서대로
		return (get<2>(_e1) < get<2>(_e2));
	}
	// 발생 빈도가 다르다면
	else {
		return (get<1>(_e1) > get<1>(_e2));
	}

}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> C;

	// 원소값, 발생빈도, 들어온 순서
	vector<tuple<int, int, int>> arr;

	for (int i = 0; i < N; ++i) {
		int temp;
		cin >> temp;

		bool isfound = false;
		for (int j = 0; j < arr.size(); ++j) {

			if (get<0>(arr[j]) == temp) {
				get<1>(arr[j]) += 1;
				isfound = true;
				break;
			}
		}

		if (!isfound) {
			arr.push_back({ temp, 1, i });
		}


		/*if (get<1>(arr[temp]) == 0) {
			get<1>(arr[temp]) += 1;
			get<0>(arr[temp]) = temp;
			get<2>(arr[temp]) = i;
		}
		else {
			get<1>(arr[temp]) += 1;
		}*/
	}

	sort(arr.begin(), arr.end(), cmp);

	for (int i = 0; i < arr.size(); ++i) {

		// 발생빈도가 0 이 아니라면
		if (get<1>(arr[i]) != 0) {

			int temp = get<1>(arr[i]);

			while (temp--) {
				cout << get<0>(arr[i]) << " ";
			}

		}
	}

	return 0;
}