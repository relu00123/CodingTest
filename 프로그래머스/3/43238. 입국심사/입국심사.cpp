#include <bits/stdc++.h>
using namespace std;

long long solution(int n, vector<int> times) {
    long long int ans = 1e18;

    // n명이 입국 심사를 위해 기다리고 있음.
    // 심사관 마다 심사하는데 걸리는 시간이 다름

    // 처음에 모든 심사대가 비어있다. 한 심사대에서는 한명만 심사가능
    // 가장 앞에 있는 사람은 비어있는 심사대 앞으로 가도 되고 다른 곳에 줄서도 됨.
    // 모든 사람이 심사를 받는데 걸리는 시간을 최소한으로 하고 싶다.

    // n : 입국심사를 기다리는 사람 수
    // times : 각 심사관이 한 명을 심사하는데 걸리는 시간 
    // 모든 사람이 심사를 받는데 걸리는 식나의 최솟값을 return 해보자. 

    long long int st = 0, en = 1e18;

    while (st <= en) {
        long long int mid = (st + en) / 2;

        // mid라는 시간동안 일처리를 다 끝낼 수 있는 지확인 
        long long int solved_ppl = 0;

        for (int i = 0; i < times.size(); ++i)
            solved_ppl += (mid / times[i]);

        //해결된 경우
        if (solved_ppl >= n) {
            en = mid - 1;
            ans = min(mid, ans);
        }

        else {
            st = mid + 1;
        }
    }

    return ans;
}

 