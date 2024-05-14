#include <bits/stdc++.h>
using namespace std;

#include <bits/stdc++.h>
using namespace std;

long long solution(int r1, int r2) {
    long long answer = 0;

    // 중심이 원점인 서로 다른 크기의 원이 두개 주어딘다.
    // 두 원 사이의 공간에 x좌표와 y좌표가 모두 정수인 점의 개수를 return 하도록 solution 함수를 완성

    // 구역 1개만 구한다음 * 4
    // 축의 정보 1개만 구한다음 * 4

    // r1, r2  는 1이상 1'000'000 이하 

    long long int r2_dist = pow(r2, 2);
    long long int r1_dist = pow(r1, 2);

    vector<int> r2_possibles;
    vector<int> r1_possibles;

    int r2_col = r2;
    for (int cur_row = 1; cur_row <= r2; cur_row++) {

        bool isedge = false;
        while (pow(cur_row, 2) + pow(r2_col, 2) >= r2_dist && r2_col >= 0)
        {
            if (pow(cur_row, 2) + pow(r2_col, 2) == r2_dist)
                isedge = true;
            r2_col--;
        }

        if (isedge)
            r2_possibles.push_back(r2_col + 2);
        else
            r2_possibles.push_back(r2_col + 1);

        
    }

    int r1_col = r1;
    for (int cur_row = 1; cur_row <= r1; cur_row++) {

       // bool isedge = false;
        while (pow(cur_row, 2) + pow(r1_col, 2) >= r1_dist && r1_col >= 0)
        {
            //if (pow(cur_row, 2) + pow(r1_col, 2) == r1_dist)
            //    isedge = true;
            r1_col--;
        }

        //if (isedge)
          //  r1_possibles.push_back(r1_col + 2);
        //else
            r1_possibles.push_back(r1_col + 1);
    }

    for (int i = 0; i < r1_possibles.size(); ++i) {
        answer += (r2_possibles[i] - r1_possibles[i]);
    }
    for (int i = r1_possibles.size(); i < r2_possibles.size(); ++i) {
        answer += (r2_possibles[i]);
    }

    return answer * 4;
}