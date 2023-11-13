#include <bits/stdc++.h>
using namespace std;

int n;
int final_small = 1e9;
int final_big = -1e9;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	vector<int> arr(n);
	for (int i = 0; i < arr.size(); ++i)
		cin >> arr[i];

	// 덧샘, 뺄셈, 곱셈, 나눗셈의 개수가 주어짐
	vector<int> opp; 

	for (int i = 0; i < 4; ++i) {
		int temp;
		cin >> temp;
		while (temp--)
			opp.push_back(i);
	}

	do {
		int cur_num = arr[0];

		for (int i = 0; i < arr.size() - 1; ++i) {
			if (opp[i] == 0) { // 덧셈의 경우
				cur_num = cur_num + arr[i+1];
			}
			else if (opp[i] == 1) { // 뺄셈의 경우
				cur_num = cur_num - arr[i+1];
			}
			else if (opp[i] == 2) { // 곱셈의 경우
				cur_num = cur_num * arr[i+1];
			}
			else if (opp[i] == 3) { // 나눗셈의 경우
				cur_num = cur_num / arr[i+1];
			}
		}

		final_small = min(final_small, cur_num);
		final_big = max(final_big, cur_num);


	} while (next_permutation(opp.begin(), opp.end()));


	cout << final_big << "\n";
	cout << final_small << "\n";

	return 0;
}