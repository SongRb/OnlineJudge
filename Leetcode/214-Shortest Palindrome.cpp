class Solution {
public:
    bool check(const string& s, int c)
    {   
        return check(s, c-1, c+1);
    }
    bool check(const string& s, int c1, int c2)
    {
        if(c1 > s.size()-1-c2) return false;
        while(c1>=0)
        {
            if(s[c1]==s[c2]) 
            {
                c1--;
                c2++;
            }
            else break;
        }
        if(c1<0) return true;
        else return false;
    }
    
    
    string shortestPalindrome(string s) {
        if(s.size()<2) return s;
        int best = s.size()-1;
        for(int i=s.size()-2;i>=1;i--)
        {
            if(check(s, i))
            {
                best = min(best, (int)s.size()-1-2*i);
            }
            if(check(s, i-1,i))
            {
                best = min(best, (int)s.size()-2*i);
            }
            if(best!=s.size()-1) break;
        }
        std::stringstream ss;
        string sub = s.substr(s.size()-best, best);
        reverse(sub.begin(), sub.end());
        ss<<sub<<s;
        return ss.str();
    }
};