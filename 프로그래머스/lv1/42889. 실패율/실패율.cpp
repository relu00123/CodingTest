#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct Info
{
    int    StageNum;
    double FailureRate;
    
    Info (int _StageNum, double _FailureRate)
        : StageNum(_StageNum)
        , FailureRate(_FailureRate)
        {}    
        

    bool operator < (const Info& _Other)
    {
        if (FailureRate != _Other.FailureRate)
        {
            return FailureRate > _Other.FailureRate;
        }
        
        else
        {
            return StageNum < _Other.StageNum;
        }
    }
};

vector<int> solution(int N, vector<int> stages) {
    
    int CurStages[501] = {0};
    int TotalGamePlayer = stages.size();
    int CurStageReached = TotalGamePlayer;
    double FailureRate = 0;
    
    vector<Info> FailureInfo;
    
    for (int i = 0; i < stages.size() ; ++i)
    {
        CurStages[stages[i]] += 1;
    }
    
    for (int i = 1 ; i <= N ; ++i)
    {
        int StuckInCurStage = CurStages[i]; 
        FailureRate = (double)StuckInCurStage / CurStageReached;  
        
        if (CurStageReached == 0)
        {
            FailureRate = 0;
        }
        
        FailureInfo.push_back(Info(i, FailureRate));
        CurStageReached -= StuckInCurStage;
    }
    
    
    // Sorting해야함 실패율에따라 내림차순으로 
    sort(FailureInfo.begin(), FailureInfo.end());
    
    vector<int> answer;
    
    for (int i = 0; i < FailureInfo.size(); ++i)
    {
        answer.push_back(FailureInfo[i].StageNum);
    }
    return answer;
}