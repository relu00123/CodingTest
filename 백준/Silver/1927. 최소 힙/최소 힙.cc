#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	// push x
	// pop

	int n; // 1 <= n <= 100'000
	cin >> n;

	vector<int> arr(100'001);


	// n개의 줄에 숫자가 주어짐
	// 0일시 pop
	// 이외의 자연수일시 push

	int cur_push_index = 1;


	for (int i = 0; i < n; ++i)
	{
		int temp;
		cin >> temp;

		if (temp == 0)
		{
			// 배열에서 가장 작은 값을 출력하고 
			// 그 값을 배열에서 출력한다.
			// 배열이 비어있는 경우 0 을 출력하면 된다.
			if (cur_push_index == 1)
			{
				cout << 0 << "\n";
			}
			else
			{
				// 출력
				cout << arr[1] << "\n";

				// 삭제
				arr[1] = arr[cur_push_index - 1];
				cur_push_index = cur_push_index - 1;
				 

				int cur_idx = 1;

				while (cur_idx < cur_push_index)
				{
					// 자식 둘중에서 더 작은 값을 위로 올린다.
					long long int left_val = 1e11, right_val = 1e11;

					// 왼쪽 자식이 있는지 확인
					if (cur_idx * 2 < cur_push_index)
						left_val = arr[cur_idx * 2];

					// 오른쪽 자식이 있는지 확인
					if (cur_idx * 2 + 1 < cur_push_index)
						right_val = arr[cur_idx * 2 + 1];
					
					long long  int smallest = min({ (long long int)arr[cur_idx], left_val, right_val });

					if (smallest == arr[cur_idx])
						break;
					else if (smallest == left_val)
					{
						swap(arr[cur_idx], arr[cur_idx * 2]);
						cur_idx = cur_idx * 2;
					}
					else if (smallest == right_val)
					{
						swap(arr[cur_idx], arr[cur_idx * 2 + 1]);
						cur_idx = cur_idx * 2 + 1;
					}
				}

				 


			}
		}

		// push 기능 구현
		else
		{
			arr[cur_push_index] = temp;
			 
			int cur_idx  = cur_push_index;

			while (cur_idx != 1)
			{
				// 부모
				int parent_val = arr[cur_idx / 2];

				// 자신
				int self_val = arr[cur_idx];

				if (parent_val > self_val)
				{
					arr[cur_idx / 2] = self_val;
					arr[cur_idx] = parent_val;

					 
					cur_idx /= 2;
				}

				else
				{
					break;
				}	 
			} 

			cur_push_index += 1;
		}
	}
	return 0;
}