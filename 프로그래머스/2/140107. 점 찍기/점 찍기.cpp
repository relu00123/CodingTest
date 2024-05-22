#include <bits/stdc++.h>
using namespace std;

long long solution(int k, int d) {
    
    // 원점 (0, 0) 으로부터 x축방향으로 a*k, y축 방향으로 b*k떨어진 위치에
    // 점을 직는다. 
    // 원점과의 거리가 d를 넘는 경우 점을 찍지 않는다. 
    
    // 정수 k와 원점과의 거리인 d가 주어졌을때 총 몇개의 점이 찍히는지 return
    long long int ans = 0;
    
    for (int y = 0; y <= d; y = y + k) {
        // y의 위치가 고정일때 x의 위치의 최대를 구한다. 
        long long int cur = (long long int)d * d - (long long int)y * y;
        long long int max_num = sqrt(cur);
        long long int cur_case = (max_num / k) + 1;
        ans += cur_case;
    }
    
    return ans;
    
    
}