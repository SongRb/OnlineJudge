class Solution {
public:    
    int countSubstrings(string s) {
        int length = s.size();
        int count = 0;
        for(int i=0;i<length;i++)
        {
            int maxLength = min(i,length-i);
            for(int j=0;j<=maxLength;j++)
            {
                if(i-j>=0 && s[i-j]==s[i+j]) {
                    // cout<<i-j<<i+j<<endl;
                    count++;}
                else break;
            }
        }
        // cout<<endl;
        for(int i=0;i<length-1;i++)
        {
            int maxLength = min(i+1,length-i-1);
            for(int j=0;j<=maxLength;j++)
            {
                if(i-j>=0 && s[i-j]==s[i+j+1]) 
                    {
                    // cout<<i-j<<i+j<<endl;
                    count++;}
                else break;
            }
        }
        return count;
    }
};