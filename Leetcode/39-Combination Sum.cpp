class Solution {
public:
    
    vector<vector<int>> result;
    
    void rec(const vector<int>& candi, vector<int>& res, int target)
    {
        if(target==0)
        {
            result.push_back(res);
        }
        else if(target>0)
        {
            int length = candi.size();
            for(int i=0;i<length;i++)
            {
                int resLen = res.size();
                if(candi[i]<=target && (resLen==0 || res[resLen-1]<=candi[i]))
                {
                    res.push_back(candi[i]);
                    rec(candi, res, target-candi[i]);
                    res.pop_back();
                }
            }   
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        if(candidates.size()==0) return result;
        vector<int> res;
        rec(candidates,res ,target);
        return result;
    }
};