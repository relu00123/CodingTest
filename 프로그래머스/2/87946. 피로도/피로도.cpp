#include <bits/stdc++.h>
using namespace std;

int final_cnt;

void calc(int _curtireness, vector<bool>& _isvis, vector<vector<int>>& _dungeon, int _cnt)
{
    final_cnt = max(final_cnt, _cnt);
    
    for (int i = 0 ; i <  _dungeon.size(); ++i) {
        if (_isvis[i] == false && _curtireness >= _dungeon[i][0])
        {
            _isvis[i] = true;
            calc(_curtireness - _dungeon[i][1], _isvis, _dungeon, _cnt + 1);
            _isvis[i] = false;
        }
    }
}


int solution(int k, vector<vector<int>> dungeons) {
    
    // ["최소 필요 피로도", "소모 피로도"]
    
   // 던전의 개수는 1개 이상 8이하 
   vector<bool> isvisited(dungeons.size(), false); 
    
   calc(k, isvisited, dungeons, 0);

   return final_cnt;
}