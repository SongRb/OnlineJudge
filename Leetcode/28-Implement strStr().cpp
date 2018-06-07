class Solution {
public:
    int strStr(string haystack, string needle) {
        int length=haystack.size();
        int length2=needle.size();
        if(length2==0) return 0;
        for(int i=0;i<length;i++)
        {
            bool found=true;
            for(int j=0;j<length2;j++)
            {
                if(i+j>=length)
                {
                    found=false;
                    break;
                }
                if(haystack[i+j]!=needle[j])
                {
                    found=false;
                    break;
                }
            }
            if(found) return i;
        }
        return -1;
    }
};