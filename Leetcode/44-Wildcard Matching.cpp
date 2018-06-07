class Solution {
public:    
    bool isMatch(string s, string p) {
        int length1 = s.size(), length2 = p.size();
        int idx1=0,idx2=0;
        int prevIdx1=0,prevIdx2=0;
        bool back = false;
        while(idx1<length1)
        {
            if(s[idx1]==p[idx2] || p[idx2]=='?')
            {
                idx1++;idx2++;
            }
            else if(idx2<length2 && p[idx2]=='*')
            {
                while(idx2<length2 && p[idx2]=='*') idx2++;
                if(idx2==length2) return true;
                
                back = true;
                prevIdx1 = idx1;
                prevIdx2 = idx2;
            }
            else if(back)
            {
                idx1 = ++prevIdx1;
                idx2 = prevIdx2;
            }
            else
            {
                return false;
            }
        }
        
        while(idx2<length2 && p[idx2]=='*')
        {
            idx2++;
        }
        
        return idx1==length1 && idx2==length2;
    }
};