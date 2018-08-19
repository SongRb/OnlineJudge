class Solution {
public:
    int romanToInt(string s) {
        int result = 0;
        int length = s.size();
        int i=0;
        unordered_map<char, int> udf {{'M',1000},{'D',500},{'L',50},{'V',5}};
        while(i<length)
        {
            if(udf.find(s[i])!=udf.end())
            {
                result+=udf[s[i]];
                i+=1;
            }
            else if(s[i]=='C')
            {
                if(i+1<length && s[i+1]=='D')
                {
                    result+=400;
                    i+=2;
                }
                else if(i+1<length && s[i+1]=='M')
                {
                    result+=900;
                    i+=2;
                }
                else
                {
                    result+=100;
                    i+=1;
                }
            }
            else if(s[i]=='X')
            {
                if(i+1<length && s[i+1]=='L')
                {
                    result+=40;
                    i+=2;
                }
                else if(i+1<length && s[i+1]=='C')
                {
                    result+=90;
                    i+=2;
                }
                else
                {
                    result+=10;
                    i+=1;
                }
            }
            else if(s[i]=='I')
            {
                if(i+1<length && s[i+1]=='V')
                {
                    result+=4;             i+=2;
                }
                else if(i+1<length && s[i+1]=='X')
                {
                    result+=9;                i+=2;
                }
                else
                {
                    result+=1;                i+=1;
                }
            }
        }
        return result;
    }
};