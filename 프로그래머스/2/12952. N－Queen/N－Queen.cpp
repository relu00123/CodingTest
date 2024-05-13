#include <bits/stdc++.h>
using namespace std;

int cnt = 0;
bool ispossible[12][12];

void calc(int currow, int max_row)
{
    if (currow > max_row) {
        cnt += 1;
        return;
    }
    
    for (int col = 0 ; col <= max_row; ++col) {
        if (ispossible[currow][col] == true) 
        {
            // 이번 말을 놓으므로써 못가는 곳들을 전부 false로 만듬
            vector<pair<int, int>> temp;
            
            // 1. 자기 열에 있는 모든 수를 false로 만든다 
            for (int temprow = currow; temprow <= max_row; ++temprow)  {
                
                if (ispossible[temprow][col] == true) {
                    temp.push_back({temprow, col});
                    ispossible[temprow][col] = false;
                }
            }
            
            int temprow = currow;
            int tempcol = col;
            // 2. 퀸의 좌측 부분을 false로 만든다.
            while (temprow <= max_row && tempcol >= 0) 
            {
                if (ispossible[temprow][tempcol] == true) {
                    temp.push_back({temprow, tempcol});
                    ispossible[temprow][tempcol] = false;
                }
                temprow += 1; tempcol -= 1;
            }
            
            temprow = currow; tempcol = col;
            while (temprow <= max_row && tempcol <= max_row) 
            {
                if (ispossible[temprow][tempcol] == true) {
                    temp.push_back({temprow, tempcol});
                    ispossible[temprow][tempcol] = false;
                }
                temprow += 1; tempcol += 1;
            }
            
            calc(currow + 1, max_row);
            
            // 이번에 false로 만들었던 것들을 다시 true로 되돌린다.
            for (pair<int, int>& e : temp)
                ispossible[e.first][e.second] = true;
        }
    } 
    
}

int solution(int n) {
    // n : 한변의 길이 (12이하)
    // 만족할 수 있는 경우의 수를 모두 구하시오
    
    // 백트래킹으로 문제를 접근할 것임
    for (int i = 0 ; i < 12; ++i) {
        for (int j = 0 ; j < 12; ++j) {
            ispossible[i][j] = true;
        }
    }
    
    calc(0, n-1);
    
    return cnt;
    
}