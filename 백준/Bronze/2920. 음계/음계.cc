#include <bits/stdc++.h>

using namespace std;

enum class Scale
{
	ASCENDING,
	DESCENDING,
	MIXED,
	DEFAULT
 };

int main()
{
	Scale CurScale = Scale::DEFAULT;
	int temp;

	for (int i = 1; i <= 8; ++i)
	{
		std::cin >> temp;

		switch (CurScale)
		{
		case Scale::ASCENDING:
		{
			if (temp != i)
				CurScale = Scale::MIXED;
		}
			break;
		case Scale::DESCENDING:
		{
			if (i != (9 - temp))
				CurScale = Scale::MIXED;
		}
			break;
		case Scale::MIXED:
		{
			std::cout << "mixed" << std::endl;
			return 0;
		}
			break;
		case Scale::DEFAULT:
		{
			if (temp == 8)
				CurScale = Scale::DESCENDING;

			else if (temp == 1)
				CurScale = Scale::ASCENDING;

			else
				CurScale = Scale::MIXED;
		}
			break;
		default:
			break;
		}

	}

	if (CurScale == Scale::ASCENDING)
	{
		std::cout << "ascending" << std::endl;
		return 0;
	}

	else if (CurScale == Scale::DESCENDING)
	{
		std::cout << "descending" << std::endl;
		return 0;
	}

}