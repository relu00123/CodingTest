#include <bits/stdc++.h>
using namespace std;

int solution(vector<vector<int>> triangle) {
   
    int tri_size = triangle.size();
    vector<vector<int>> dp(tri_size, vector<int>(tri_size, 0));
    
    dp[0][0] = triangle[0][0];
    
    for (int row = 1; row < tri_size; ++row) {
        for (int col = 0; col <= row; ++col) {
            
            if (col == 0) {
                dp[row][col] = dp[row - 1][col] + triangle[row][col];
            }
            
            else if (col == row ) {
                dp[row][col] = dp[row-1][col - 1] + triangle[row][col];
            }
            
            else {
                dp[row][col] = max(dp[row - 1][col - 1] , dp[row - 1][col]) + triangle[row][col];
            }   
        }
    }
    
    int ans = 0;
    for (int i = 0 ; i < tri_size; ++i)
        ans = max(ans, dp[tri_size - 1][i]);
    
    return ans;
}