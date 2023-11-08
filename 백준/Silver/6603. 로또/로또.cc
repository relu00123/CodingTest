#include <bits/stdc++.h>
using namespace std; 

int k;
vector<int> arr;
vector<int> indexarr;
bool isused[13];

void func(int n)
{
	if (n == 6) {
		for (int i = 0; i < 6; ++i)
			cout << arr[indexarr[i]] << " ";
		cout << "\n";
		return;
	}

	vector<int> curused;
	
	for (int i = 0; i < arr.size(); ++i)
	{
		if (!isused[i])
		{
			isused[i] = true;
			indexarr.push_back(i);
			curused.push_back(i);
			func(n + 1);
			indexarr.pop_back();
		}
	}

	for (int i = 0; i < curused.size(); ++i)
		isused[curused[i]] = false;

	return;

}


int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	while (true)
	{
		cin >> k;

		if (!k)
			break;

		arr.clear();
		indexarr.clear();
		fill(isused, isused + 13, false);
		
		for (int i = 0; i < k; ++i) {
			int temp;
			cin >> temp;
			arr.push_back(temp);
		}
		
		// 원소 k개 중에서 6개를 뽑는다.
		// 단, 조합이다. 주어지는 원소는 서로 다른 원소이기에
		// 중복은 고려하지 않아도 된다.
		// 주어지는 수는 오름차순으로 주어져 있기 때문에 정렬할 
		// 필요도 없음.
		func(0);
		cout << "\n";
	}

	return 0;
}