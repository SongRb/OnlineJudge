class Solution {
public:
    
    vector<string> result;
    // 0 - left; 1 - right
    void rec(int n, int lc, int rc, int stkSize, vector<int>& vec)
    {
        // cout<<lc<<" "<<rc<<" "<<stkSize<<endl;
        if(lc==n && rc==n && stkSize==0)
        {
            string res;
            for(const auto& i:vec)
            {
                res.append(1,i==0?'(':')');
            }
            result.push_back(res);
        }
        else
        {
            if(lc<n)
            {
                vec.push_back(0);
                rec(n,lc+1,rc,stkSize+1,vec);
                vec.pop_back();
            }
            if(rc<n)
            {
                if(stkSize>0)
                {
                    vec.push_back(1);
                    rec(n,lc,rc+1,stkSize-1,vec);
                    vec.pop_back();
                }
            }
        }
    }
    
    vector<string> generateParenthesis(int n) {
        if(n==0)
        {
            result.push_back("");
            return result;
        }
        else
        {
                 vector<int> vec;
        vec.push_back(0);
        rec(n,1,0,1,vec);
        return result;   
        }
    }
};