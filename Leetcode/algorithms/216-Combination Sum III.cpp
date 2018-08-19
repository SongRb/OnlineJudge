class Solution {
public:
    vector<vector<int>> result;
    
    void rec(int num, int k, int n, vector<int>& res)
    {
        if(n==0 && k==0)
        {
            result.push_back(res);
        }
        else if(k>0 && n>0 && n<=num*(num+1)/2)
        {
            rec(num-1,k,n,res);
            if(n>=num)
            {
                res.push_back(num);
                rec(num-1,k-1,n-num,res);
                res.pop_back();   
            }
        }
    }
    
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> res;
        rec(9, k, n, res);
        return result;
    }
};