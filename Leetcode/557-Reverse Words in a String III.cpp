class Solution {
public:
    void reverseString(string& s, int from, int to)
    {
        while(from<to)
        {
            char t = s[from];
            s[from++] = s[to];
            s[to--] = t;
        }
    }
    string reverseWords(string s) {
        int length = s.size();
        int i=0;
        while(i<length)
        {
            int j = i;
            while(j<length && s[j]!=' ')
            {
                j++;
            }
            reverseString(s,i,j-1);
            i = j+1;
        }
        return s;
    }
};