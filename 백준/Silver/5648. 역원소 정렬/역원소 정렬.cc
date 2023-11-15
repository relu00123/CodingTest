#include <bits/stdc++.h>
using namespace std;

int cnt;

vector<long long int> arr;



int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);


	int count;
	cin >> count;

	while (count--) {
		long long int temp;
		cin >> temp;
		

		int digit = 1;
		long long int num = 0;
		while (temp) {
		 
				if (num == 0) {

					if (temp % 10 == 0) {
						temp /= 10;
					}

					num = temp % 10;
					temp /= 10;
				}
				
				else {
					num *= 10;
					num += temp % 10;
					temp /= 10;
				}
		 
		}

		arr.push_back(num);
	}

	sort(arr.begin(), arr.end());

	for (int i = 0; i < arr.size(); ++i)
		cout << arr[i] << "\n";

	return 0;
	 
}