class Solution {
public:
    
    bool compare(const string& num1, const string& num2)
    {
        string a = num1+num2;
        string b = num2+num1;
        if(a.compare(b)>0) return false;
        else return true;
    }
    
    string largestNumber(vector<int>& nums) {
        vector<string> numStr;
        for(auto& num:nums) numStr.push_back(to_string(num));
        sort(numStr.begin(), numStr.end(), [] (const auto& lhs, const auto& rhs) {
            string a = lhs+rhs;
            string b = rhs+lhs;
            if(a.compare(b)>0) return true;
            else return false;
        });
        
        if (numStr.size() ==0 || numStr[0]=="0") return "0";
        
        string result;
        int isFirst = true;
        for(auto& str: numStr) result+=str;
        return result;
    }
};