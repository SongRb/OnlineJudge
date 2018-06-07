class Solution {
public:
    bool isNumber(string s) {
        int length = s.size();
        if(length==0) return false;
        int i=0;
        while(i<length && s[i]==' ')
            i++;
        if(s[i]=='-' || s[i] =='+') i++;
        
        int j=length-1;
        while(j>=i && s[j]==' ')
            j--;
 
        
        if(i==length) return false;
        if(j==i)
        {
            if(s[i]=='e' || s[i]=='.') return false;
        }
        bool hasDot = false;
        bool hasE = false;
        bool preNum = false;
        // if(s[i]=='0')
        // {
        //     if(i == length-1) return true;
        //     else if(i<length -1 && s[i+1]!='.') return false; 
        //     else hasDot = true;
        // }
        int start = i;
        for(;i<=j;i++)
        {
            if(s[i]=='.')
            {
                if(hasDot || hasE) return false;
                if(i<length-1 && s[i]=='e') return false;
                hasDot = true;
            }
            else if(s[i]=='e')
            {                
                if(!preNum||hasE||i==j) return false;
                if(i<j && (s[i+1]=='+' || s[i+1] == '-'))
                {
                    if(i+1==j) return false;
                    else i++;
                }
                hasE = true;
            }
            else if(s[i]>='0' && s[i]<='9') {preNum = true; continue;}
            else return false;
        }              

        return true;
    }
};