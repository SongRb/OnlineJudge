class Solution {
public:
    int lengthOfLastWord(string s) {
        int length = s.size();
        if(length==0) return 0;
        int size = 0;
        int i=length-1;
        
        while(i>=0 && s[i]==' ') i--;
        if(i==-1) return size;
        int tmpSize = i;
        while(i>=0 && s[i]!=' ') i--;
        size = tmpSize-i;
        return size;
    }
};