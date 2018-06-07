class Solution {
public:
    string str, pat;
    int sLength,pLength;
    
    bool match(int idx1, int idx2)
    {
        if(idx1==-1 && idx2 == -1) return true;
        else if(idx1 != -1 && idx2 !=-1)
        {
            if(pat[idx2]=='.') return match(idx1-1,idx2-1);
            else if(pat[idx2]=='*') 
            {          // 
                return ((str[idx1] == pat[idx2-1] || pat[idx2-1] == '.'  ) && match(idx1-1,idx2)) 
                    || ((str[idx1] == pat[idx2-1] || pat[idx2-1] == '.'  ) && match(idx1-1,idx2-1)) 
                    ||  match(idx1,idx2-2);
            } 
            else
            {
                return (str[idx1] == pat[idx2] || pat[idx2] == '.'  ) && match(idx1-1,idx2-1);
            }
        }
        else if(idx1 == -1 && idx2!=-1)
        {
            if(pat[idx2]=='*') return match(idx1,idx2-2);
            else return false;
        }
        
        else return false;
    
    }
    
    bool isMatch(string s, string p) {
        str = s; pat = p;
        sLength = str.size(); pLength = pat.size();
        
        return match(sLength-1,pLength-1);
    }
};