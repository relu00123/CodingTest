#include <bits/stdc++.h>
using namespace std;



struct info
{
	int  productnum;
	bool appeared;
	int  nextappearindex;


	bool operator<(const info _other) const
	{
		if (this->appeared == true && _other.appeared == false)
		{
			return false;
		}

		else
		{
			return this->nextappearindex > _other.nextappearindex;
		}
	}
};




 
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, k;

	cin >> n;     // n이 멀티탭 개수
	cin >> k;     // k가 제품


	if (k <= n) {
		cout << "0";
		return 0;
	}

	vector<info> checked;
	vector<int> arr(k);
	 

	bool shoulddelete;

	int plug_count = 0;

	for (int i = 0; i < k; ++i)
	{
		cin >> arr[i]; 
	}


	for (int i = 0; i < k; ++i)
	{
		if (checked.size() < n)
		{
			bool isSameDataExisted = false;

			for (int a = 0; a < checked.size(); ++a)
			{
				if (checked[a].productnum == arr[i])
					isSameDataExisted = true;
			}
			
			if (!isSameDataExisted)
			{
				info data;
				data.productnum = arr[i];
				data.appeared = false;
				data.nextappearindex = 2000;
				checked.push_back(data);
			} 
		}

		else
		{
			int passed = true;
			shoulddelete = true;

			while (passed)
			{
				for (int j = 0; j < checked.size(); ++j)
				{
					if (checked[j].productnum == arr[i])
					{

						shoulddelete = false;
						if (checked[j].appeared == false)
						{
							checked[j].appeared = true;
							checked[j].nextappearindex = i;
						}
					}


					else
					{
						passed = false;
						 
					}
				}

				passed = false;
			}

			// 가장 최근에 발생한 위치를 기록해야한다.
			for (int j = i; j < k; ++j)
			{
				for (int l = 0; l < checked.size(); ++l)
				{
					if (arr[j] == checked[l].productnum && checked[l].appeared == false)
					{
						checked[l].appeared = true;
						checked[l].nextappearindex = j;
					}
				}
			}


			// sorting 작업 진행해야함. 멀티탭에서 사출해야할 순서로
			if (shoulddelete == true)
			{
				sort(checked.begin(), checked.end());

				plug_count += 1;
				checked.erase(checked.begin());


				if (checked.size() < n)
				{
					 
						info data;
						data.productnum = arr[i];
						data.appeared = false;
						data.nextappearindex = 2000;
						checked.push_back(data);
				 
				}

			}
		}




		/*cout << "index : " << i << " and current pluged : ";
		for (int i = 0; i < checked.size(); ++i)
		{
			cout << checked[i].productnum << " ";
		}
		cout << "\n";*/

		for (int i = 0; i < checked.size(); ++i)
		{
			checked[i].appeared = false;
			checked[i].nextappearindex = 2000;

		}

	}

	cout << plug_count;

	return 0;

}