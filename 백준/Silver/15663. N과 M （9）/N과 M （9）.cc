#include <bits/stdc++.h>
using namespace std;


int N, M;

// first : Value, Second : Count
// Count가 0이라면 isused = true라고 볼 수 있음.
list<pair<int, int>> arr; 
vector<int> solution;

void func(int n)
{
	if (n == M) {
		for (int i = 0; i < solution.size(); ++i)
			cout << solution[i] << " ";
		cout << "\n";
		return;
	}

	for (auto iter = arr.begin(); iter != arr.end(); ++iter) {
		if( (*iter).second  != 0)
		{
			(*iter).second -= 1;
			solution.push_back((*iter).first);
			func(n + 1);
			(*iter).second += 1;
			solution.pop_back();
		}
	}

	return;
}


int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M;

	for (int i = 0; i < N; ++i) {
		int Temp;
		cin >> Temp;

		bool isrepeat = false;
		for (list<pair<int, int>>::iterator iter = arr.begin(); iter != arr.end(); ++iter) {
			// 중복된 경우
			if ((*iter).first == Temp) {
				isrepeat = true;
				(*iter).second += 1;
			}
		}

		if (!isrepeat)
			arr.push_back({ Temp, 1 });
	}
		
	arr.sort();

	/*for (list<pair<int, int>>::iterator iter = arr.begin(); iter != arr.end(); ++iter)
	{
		cout << "(" << (*iter).first << "," << (*iter).second << ")\n";
	}*/

	func(0);

	return 0;
}