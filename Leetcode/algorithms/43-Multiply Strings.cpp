class Solution {
public:
    void pvec(const vector<int>& vec)
    {
        for(const auto& i:vec) cout<<i<<" ";
        cout<<endl;
    }
    
    string multiply(string num1, string num2) {
        vector<char> charMap {'0','1','2','3','4','5','6','7','8','9'};
        
        
        if(num1=="0" || num2=="0") return "0";
        else if(num1 == "1") return num2;
        else if(num2 == "1") return num1;
        else
        {
            string& l = num1.size()>num2.size()?num1:num2;
            string& s = num1.size()<=num2.size()?num1:num2;
            int sLength = s.size();
            int lLength = l.size();
            int totalLength = sLength+lLength;
            vector<int> result = vector<int>(totalLength,0);
            for(int i=sLength-1;i>=0;i--)
            {
                // pvec(result);
                int baseIndex = (totalLength - 1) - (sLength-1-i);
                int carry = 0;
                for(int j=lLength-1;j>=0;j--)
                {
                    int tmp2 = (l[j]-'0')*(s[i]-'0');
                    
                    int tens = tmp2/10;
                    int ones = tmp2%10;
                    // max:81 
                    int inc = lLength-1-j;
                    
                    result[baseIndex-inc]+= ones+carry;
                    carry = result[baseIndex-inc]/10;
                    result[baseIndex-inc]%=10;
                    
                    result[baseIndex-inc-1]+= tens+carry;
                    carry = result[baseIndex-inc]/10;
                    result[baseIndex-inc]%=10;
                    
                }
            }
            int idx = 0;
            string resultStr;
            while(result[idx]==0)idx++;
            while(idx<totalLength)
            {
                resultStr.append(1,charMap[result[idx++]]);
            }
            return resultStr;
        }
    }
};