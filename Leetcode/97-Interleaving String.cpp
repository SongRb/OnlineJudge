class Solution {
public:
    string str1,str2,str;
    bool isInterleave(int idx1, int idx2, int idx3) {
        bool result = false;
        if(idx3==str.size()) return idx1==str1.size() && idx2==str2.size();
        if(idx1<str1.size() && str1[idx1]==str[idx3]) result = result || isInterleave(idx1+1,idx2,idx3+1);
        if(result) return result;
        if(idx2<str2.size() && str2[idx2]==str[idx3]) result = result || isInterleave(idx1,idx2+1,idx3+1);
        return result;
    }
    
    
    bool isInterleave(string s1, string s2, string s3) {
        if(s1=="") return s2==s3;
        if(s2=="") return s1==s3;
        str1 = s1;
        str2 = s2;
        str = s3;
        return isInterleave(0,0,0);
    }
};