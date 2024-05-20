#include <bits/stdc++.h>
using namespace std;

int solution(int n, int k, vector<int> enemy) {
   
    // n명의 병사를 보유하고 있다.
    // 매라운드마다 enemy[i]마리의 적이 등장
    // enemy[i]명의 병사를 소모하여 enemy[i]마리의 적을 막을 수 있다. 
    // 남은 병사의 수보다 현재 라운드의 적의 수가 더 많으면 게임 종료
    // k 는 무적을 사용할 수 있는 횟수이다. 
    
    // n은 최대 10억명
    // k는 최대 500'000 개
    // enemy.size() 는 최대 1'000'000개
    // enemy[i]는 최대 1'000'000
    
    // priority_queue를 사용할 것이고
    // 여기에는 무적권을 사용했을때의 save한 병사수가 들어간다.
    // 최소 힙을 사용한다.
    
    priority_queue<int, vector<int>, greater<>> pq;
    
    int round = enemy.size();
    for (int i = 0; i < enemy.size(); ++i) {
        
        // 아직 무적 카드가 남아있으면 사용한다.
        if (k > 0) {
            k--;
            pq.push(enemy[i]);
        }
        
        // 무적 카드가 남아 있지 않은 경우
        else {
            // Step1. 현재 들어오는 것이 pq보다 큰지 확인한다.
            if (enemy[i] > pq.top()) {
                int cur = pq.top();
                pq.pop();
                pq.push(enemy[i]);
                n -= cur;   // pq에 들어있었던 가장 작은 값을 소모
            }
            
            else {
                // 이 경우는 현재 들어오는 것이 가장 작은 경우이다.
                n -= enemy[i];
            }
            
            if ( n < 0 ) {
                round = i  ;
                break;
            }
                
        }
    }
    
    return round;
    
    
}