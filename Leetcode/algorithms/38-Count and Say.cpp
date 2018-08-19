class Solution {
public:
    string countAndSay(int n) {
        vector<char> num {'0','1','2','3','4','5','6','7','8','9'};
        string str = "1";
        for(int i=1;i<n;i++)
        {
            int length = str.size();
            string newStr;
            int j=0;
            while(j<length)
            {
                int cnt = 0;
                int t = j;
                while(j<length && str[j]==str[t]) {j++;}
                // j is first index that str[j]!=str[t]
                newStr.append(1,num[j-t]);
                newStr.append(1,str[t]);
            }
            // cout<<newStr<<endl;
            str = newStr;
        }
        return str;
    }
};