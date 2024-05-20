#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> numbers, int target) {
    
    // numbers : 숫자가 담긴 배열
    // target : 타겟 넘버
    
    // 숫자를 적절히 더하고 빼서 타겟 남버를 만드는 경우의 수를 return 하시오
    // numbers의 개수는 2개 이상 20개 이하이다. 
    
    // Bfs로 풀어보자
     
    
    // 현재 숫자, 몇번째 index를 넣어야 하는지
    queue<pair<int, int>> q;
    
    q.push({0, 0});
    int ans = 0;
    
    while (!q.empty()) {
        auto [cur_num, cur_idx] = q.front(); q.pop();
        if (cur_idx == numbers.size()) {
            if (cur_num == target) {
                ans += 1;
                
            }
             continue;
        }
        
        q.push({cur_num + numbers[cur_idx], cur_idx + 1});
        q.push({cur_num - numbers[cur_idx], cur_idx + 1});
    }
    
    return ans;
    
}