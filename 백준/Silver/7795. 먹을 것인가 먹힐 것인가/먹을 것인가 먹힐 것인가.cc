#include<bits/stdc++.h>
using namespace std;

int Testcase;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> Testcase;

	while (Testcase--) {
		int N, M;
		cin >> N >> M;
		vector<int> A(N);
		vector<int> B(M);
		int cnt = 0;

		for (int i = 0; i < N; ++i) 
			cin >> A[i];

		sort(A.begin(), A.end());

		for (int i = 0; i < M; ++i)
			cin >> B[i];

		sort(B.begin(), B.end());


		int idx = 0;
		for (int i = 0; i < A.size(); ++i) {
			
			int curfirst = A[i];

			int idx = 0;

			while (idx <= B.size())
			{
				if (idx == B.size()) {
					cnt += B.size();
					break;
				}

				if (curfirst <= B[idx]) {
					cnt += idx;
					break;
				}

				else {
					idx += 1;
				}
					
			}


		}

		cout << cnt << "\n";
	}

	return 0;
}