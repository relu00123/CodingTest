#include <bits/stdc++.h>

using namespace std;

struct Member_Info
{
public:
	int Age;
	int order;
	string Name;
};

bool Cmp(Member_Info _First, Member_Info _Second)
{
	if (_First.Age != _Second.Age)
	{
		return (_First.Age < _Second.Age);
	}

	else
	{
		return  (_First.order < _Second.order);
	}


}


int main()
{
	int number;

	vector<Member_Info> Buffer;

	Member_Info Temp;


	std::cin >> number;

	for (int i = 1; i <= number; ++i)
	{
		std::cin >> Temp.Age;
		std::cin >> Temp.Name;
		Temp.order = i;

		Buffer.push_back(Temp);
	}

	sort(Buffer.begin(), Buffer.end(), Cmp);


	for (int i = 0; i < number; ++i)
	{
		std::cout << Buffer[i].Age << " " << Buffer[i].Name << "\n";
	}

	return 0;


}