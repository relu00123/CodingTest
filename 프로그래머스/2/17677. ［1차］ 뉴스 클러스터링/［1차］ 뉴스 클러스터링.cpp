#include <bits/stdc++.h>
using namespace std;

void calc(unordered_map<string, int>& out, string& in) {
    for (int i = 0; i < in.size() - 1; i++)
    {
        if (!(('a' <= in[i] && in[i] <= 'z') || ('A' <= in[i] && in[i] <= 'Z'))) continue;
        if (!(('a' <= in[i + 1] && in[i + 1] <= 'z') || ('A' <= in[i + 1] && in[i + 1] <= 'Z'))) continue;

        string key; key.push_back(in[i]); key.push_back(in[i + 1]);

        
        transform(key.begin(), key.end(), key.begin(), ::tolower);

        if (out.find(key) == out.end()) {
            out[key] = 1;
        }
        else
        {
            out[key] += 1;
        }
    }
}

int solution(string str1, string str2) {

    unordered_map<string, int> st1;
    unordered_map<string, int> st2;

    calc(st1, str1);
    calc(st2, str2);

    int top = 0; int bottom = 0;


    for (auto iter = st1.begin(); iter != st1.end(); ) {
       
        auto st2iter = st2.find(iter->first);

        if (st2iter == st2.end())
            bottom += iter->second;
        else
        {
            top += min(iter->second, st2iter->second);
            bottom += max(iter->second, st2iter->second);

            st2.erase(st2iter);
        }

        iter = st1.erase(iter);
    }


    for (auto iter = st2.begin(); iter != st2.end(); )
    {
        bottom += iter->second;

        iter = st2.erase(iter);
    }

    float jackads;
    if (bottom == 0)
        jackads = 1;
    else
        jackads = (float)top / bottom;

    return (int)(jackads * 65536 );
}