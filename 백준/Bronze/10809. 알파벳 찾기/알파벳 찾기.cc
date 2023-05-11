#include <bits/stdc++.h>

using namespace std;

int main()
{
	int num[26];
	std::fill_n(num, 26, -1);

	string str;
	std::cin >> str;

	for (int i = 0; i < str.size(); ++i)
	{
		// 처음 해당 알파벳이 등장찬경우
		if (num[str[i] - 'a'] == -1)
		{
			num[str[i] - 'a'] = i;
		}
	}


	for (int i = 0; i < 26; ++i)
	{
		std::cout << num[i] << " ";
	}

	std::cout << endl;

	return 0;

}