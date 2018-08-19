class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int length = strs.size();
        if(length==0) return "";
        
        int minLength = strs[0].size();
        int minIndex = 0;
        for(int i=0;i<length;i++)
        {
            if(minLength>strs[i].size())
            {
                minLength = strs[i].size();
                minIndex = i;
            }
        }
        // cout<<"WWW: "<<minIndex<<" "<<strs[minIndex]<<endl;
        
        string result = strs[minIndex];
        int resLength=result.size();
        if(resLength==0) return "";
        for(int i=0;i<length;i++)
        {
            int tmpLength = strs[i].size();
            for(int j=0;j<resLength;j++)
            {
                if(j>tmpLength || result[j]!=strs[i][j]) 
                {
                    resLength = j;
                    break;
                }
            }
            if(resLength==0) return "";
        }
        return result.substr(0, resLength);    
    }
};