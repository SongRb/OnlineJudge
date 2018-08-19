class Solution {
public:
    vector<vector<string>> result;
    int totalNum;
    void vec2str(const vector<pair<int,int>>& sol)
    {
        vector<string> solStr;
        for(int i=0;i<totalNum;i++)
        {
            string str = string(totalNum,'.');
            str[sol[i].second] = 'Q';
            solStr.push_back(str);
        }
        result.push_back(solStr);
    }
    
    bool check(const pair<int,int>& lhs, const pair<int,int>&rhs)
    {
        return lhs.first!=rhs.first && lhs.second!=rhs.second && abs(lhs.second-rhs.second)!=abs(lhs.first-rhs.first);
    }
    
    void solve(vector<pair<int,int>>& sol, int num){
        if(num==totalNum)
        {
            vec2str(sol);
        }
        else
        {
            for(int i=0;i<totalNum;i++)
            {
                bool isConflict = false;
                auto candidate = make_pair(num,i);
                for(auto it = sol.begin();it!=sol.end();it++)
                {
                    if(!check(candidate,*it))
                    {
                        isConflict = true;
                        break;
                    }
                }
                if(!isConflict)
                {
                    sol.push_back(candidate);
                    solve(sol,num+1);
                    sol.pop_back();
                }
            }
        }
    }
    
    
    vector<vector<string>> solveNQueens(int n)
    {
        totalNum = n;
        vector<pair<int,int>> vec;
        solve(vec,0);
        return result;
    }
};