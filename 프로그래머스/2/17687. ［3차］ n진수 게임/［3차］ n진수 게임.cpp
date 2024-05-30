#include <bits/stdc++.h>
using namespace std;

string calc(int num, int digit) {
    string an;
    
    while (num >= digit) {
        int temp = num % digit;
        num = num / digit;
        char char_temp;
        if (temp >= 10)
            char_temp = ('A' + (temp - 10));
        else
            char_temp = ('0' + temp);
        an.push_back(char_temp);
    }
    
    if (num >= 10)
        an.push_back('A' + (num - 10));
    else
        an.push_back('0' + num);
    
    reverse(an.begin(), an.end());
    return an;
}

bool calculate(string& curnum, int& curidx , string& totans) {
    totans.push_back(curnum[curidx]);
    
    curidx++; 
    
    if (curidx == curnum.size()) 
    {
        curidx = 0;
        return false;
    }
    
    return true;
    
}

string solution(int n, int t, int m, int p) {
    string ans = "";
    string tot = "";
    
    // n : 진법
    // t : 미리 구할 숫자의 개수 
    // m : 게임에 참가하는 인원
    // p : 튜브의 순서 
    
    // 튜브가 말해야 하는 숫자 t개를 공백없이 나타낸 문자열을 return
    // 전체 문자열을 구한다음에 m개씩 건너 뛰어서 ans에 집어넣으면됨
    
    // 100'000 번의 게임에 해당하는 값을 전부다 집어넣어주자. 
    int curnum = 0;
    string curnum_str = "0";
    int idx = 0;
    bool isfinished = false;
    for (int i = 0 ; i < 100'000; ++i) {
        if (isfinished == true) {
            curnum += 1;
            isfinished = false;
            // 해당 숫자를 n진법으로 변환
            curnum_str = calc(curnum, n);
        }
            
        if (calculate(curnum_str, idx, tot) == false) {
            isfinished = true;
        }
    }
    
    int tube_idx = p - 1;
    while (ans.size() != t) {
        ans.push_back(tot[tube_idx]);
        tube_idx += m;
    }
    
    
    return ans;
}