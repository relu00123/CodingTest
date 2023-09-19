#include <string>
#include <vector>

using namespace std;

string solution(string _Input) {
    // 1 단게 법칙 수행
if (_Input == "")
{
	string Result = "";
	return Result;
}
	 

// 2 단계 법칙 수행
// 문자열을 균형잡인 문자열 U와 V로 분리
string U;
string V; 

int U_left_Count = 0;
int U_Right_Count = 0;
bool IsLegimateString = true;

if (_Input == "")
	IsLegimateString = false;

for (int i = 0; i < _Input.size(); ++i)
{
	if (_Input[i] == '(')
	{
		U.push_back('(');
		U_left_Count += 1;
	}

	else if (_Input[i] == ')')
	{
		U.push_back(')');
		U_Right_Count += 1;
	}

	//  올바른 괄호 문자열인지 판단.
	if (IsLegimateString != false)
	{
		if (U_left_Count - U_Right_Count < 0)
		{
			IsLegimateString = false;
		}
		else
		{
			 
		}

	}

	if (U_left_Count == U_Right_Count)
	{
		if (i < _Input.size() -1)
		{

			for (int j = i + 1 ; j < _Input.size(); ++j)
			{
				V.push_back(_Input[j]);
			}
		}
		break;
	}
}

 
// 3단계
if (IsLegimateString)
{
	string Temp = solution(V);

	string Answer = U + Temp;

	return Answer;
}

else  // 4단계
{
	// 4-1
	string Temp;
	Temp.push_back('(');

	// 4-2
	Temp = Temp + solution(V);

	// 4-3
	Temp.push_back(')');

	// 4-4
	if (U.size() > 2)
	{
		for (int i = 1; i < U.size() - 1; ++i)
		{
			if (U[i] == '(')
			{
				Temp.push_back(')');
			}
			else if (U[i] == ')')
			{
				Temp.push_back('(');
			}
		}
	}

	return Temp;
}
}