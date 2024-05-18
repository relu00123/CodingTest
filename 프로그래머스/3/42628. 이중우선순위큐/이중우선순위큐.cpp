#include <bits/stdc++.h>
using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> ans;
    
    set<int> db;
    
    for (string& cur_string : operations) {
        if (cur_string[0] == 'I') {
            
            // 음수인지 판독해야함
            if (cur_string[2] == '-') {
                string temp(cur_string.begin() +3, cur_string.end());
                int temp_num = stoi(temp);
                db.insert(-temp_num);
            }
            
            else {
                string temp(cur_string.begin() + 2, cur_string.end());
                int temp_num = stoi(temp);
                db.insert(temp_num);
            }
        }
        else if (cur_string[0] == 'D')
        {
            if (cur_string[2] == '1') {
                // 큐에서 최댓값을 삭제합니다.
                if (db.empty()) continue;
                db.erase(prev(db.end()));
            }
            else {
                // 큐에서 최솟값을 삭제합니다.
                if (db.empty()) continue;
                db.erase(db.begin());
            }
        }  
    }
    
    if (db.size() == 0) {
        ans.push_back(0);
        ans.push_back(0);
    }
    else {
        ans.push_back(*prev(db.end()));
        ans.push_back(*db.begin());
        
    }
    

    return ans;
}