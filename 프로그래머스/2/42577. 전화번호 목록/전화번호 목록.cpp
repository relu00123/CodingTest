#include<bits/stdc++.h>
using namespace std;

bool solution(vector<string> phone_book) {
        
    vector<pair<int, string>> assist;
    
    for (int i = 0 ; i < phone_book.size(); ++i) 
        assist.push_back({phone_book[i].size(), phone_book[i]});
    
    sort(assist.begin(), assist.end());
    
    
    unordered_set<string> db;
    
    for (int i = 0; i < assist.size(); ++i) {
        if (db.empty()) {
            db.insert(assist[i].second);
        }
        else {
            string cur_string = assist[i].second;
            for (int j = 0 ; j <= cur_string.size(); ++j) {
                if (db.find(cur_string.substr(0, j)) != db.end())
                    return false;
            }
            db.insert(cur_string);
        }
    }
    
    return true;
    
}