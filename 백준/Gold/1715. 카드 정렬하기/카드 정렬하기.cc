#include <bits/stdc++.h>

 

using namespace::std;

struct cmp
{
	bool operator()  (int a, int b)
	{
		return a > b;
	}
};

int main()
{
	int N;
	priority_queue<int, vector<int>, cmp> CardInfo;

	int Total = 0;

	std::cin >> N;

	int Temp;

	for (int i = 0; i < N; ++i)
	{
		std::cin >> Temp;
		CardInfo.push(Temp);
	}
	
	// 카드 덱이 하나만 있을 경우 바로 Return
	if (N == 1)
	{
		std::cout << 0 << std::endl;

		return 0;
	}
	else
	{
		while (CardInfo.size() != 1)
		{
			int First = CardInfo.top();
			CardInfo.pop();
			int Second = CardInfo.top();
			CardInfo.pop();

			Total += (First + Second);

			//std::cout << Total << std::endl;


			CardInfo.push(First + Second);
		}

		 

		std::cout << Total << std::endl;

		return 0;


	}
 
}