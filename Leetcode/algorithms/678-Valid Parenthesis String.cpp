class Solution {
public:
    
    bool rec(const string& s, int stk, int idx)
    {
        if(idx==s.size())
        {
            return stk==0;
        }
        else
        {
            if(stk<0) return false;
            else if(s[idx]=='(') return rec(s,stk+1,idx+1);
            else if(s[idx]==')') return rec(s, stk-1, idx+1);
            else return rec(s,stk-1,idx+1) || rec(s, stk+1,idx+1) || rec(s,stk,idx+1);
         }
    }
    
    bool checkValidString(string s) {
        return rec(s,0,0);
    }
};