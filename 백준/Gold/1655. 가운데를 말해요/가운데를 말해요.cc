#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	// 백준이가 정수를 하나씩 외칠 때마다 동생은
	// 지금까지 백준이가 말한 수 중에서 중간값을 말해야 한다.
	// 만약에 짝수개를 외쳤다면 그 중간에 있는 두 수중 작은 수를 말해야 한다.

	// ex
	// 1 5 2 10 -99 7 5
	// 1 1 2 2   2  2 5


	// 외치는 정수의 수는 최대 100'000개 
	int  n; cin >> n;


	// 연산량 1천만번 이하로 문제를 풀어야 한다. 
	// n^2 불가
	// n log n  가능
	// 즉 한번 찾을 때마다 logn의 연산속도를 지니고 있어야 함 
	
	priority_queue<int> less_pq;
	priority_queue<int, vector<int>, greater<>> large_pq;

	for (int i = 0; i < n; ++i) {
		int temp; cin >> temp;

		// 지금 총 i개의 숫자가 저장되어 있는 상태임.
		if (i % 2 == 0) // 짝수개가 저장되어 있는 경우
		{
			if (i == 0) {
				cout << temp << "\n";
				large_pq.push(temp);
			}


			else {
				int assist = large_pq.top();

				if (temp >= assist) {
					large_pq.push(temp);
					cout << large_pq.top() << "\n";
				}

				else {
					less_pq.push(temp);
					cout << less_pq.top() << "\n";
				}
			}
		}


		else { // 지금 홀수개가 있는 경우

			if (i == 1) {
				if (temp > large_pq.top()) {
					int lift = large_pq.top();
					large_pq.pop();
					less_pq.push(lift);
					large_pq.push(temp);
				}

				else {
					less_pq.push(temp);
				}

				cout << less_pq.top() << "\n";

			}

			else {

				if (large_pq.size() < less_pq.size()) {
					if (temp < less_pq.top()) {
						int lift = less_pq.top();
						less_pq.pop();
						large_pq.push(lift);
						less_pq.push(temp);
					}

					else {
						large_pq.push(temp);
					}

					cout << min(large_pq.top(), less_pq.top()) << "\n";
				}

				else { // 큰쪽이 더 많은 경우
					if (temp > large_pq.top()) {
						int lift = large_pq.top();
						large_pq.pop();
						less_pq.push(lift);
						large_pq.push(temp);
					}

					else {
						less_pq.push(temp);
					}

					cout << min(large_pq.top(), less_pq.top()) << "\n";
				}
			}
		}

	}


	return 0;
}