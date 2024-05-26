#include <bits/stdc++.h>
using namespace std;

int solution(string word) {
    // 단어 하나 word가 매개변수로 주어졌을때, 
    // 이 단어가 사전에서 몇 번째 단어인지 return 하도록 하는 solution함수를 작성하시오
    
    // word의 길이는 1 이상 5이하이다.
    // word는 대문자 'A', 'E', 'I', 'O', 'U'로만 이루어져 있다. 
    
    
    int assis[5] = {781, 156, 31, 6, 1};
    
    
    unordered_map<char, int> db;
    db['A'] = 0;
    db['E'] = 1;
    db['I'] = 2;
    db['O'] = 3;
    db['U'] = 4;
    
    int ans = 0;
    // abcd 
    for(int i = 0 ; i < word.size(); ++i) {
        
        ans += 1;
        int idx = i;
        
        int cur_alphabet_idx = db[word[i]];
        ans += cur_alphabet_idx * assis[idx];
        
    }
    
    return ans;
}