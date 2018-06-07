class Solution {
public:
    vector<string> result;
    vector<string> charVec {"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    
    void search(const string& digits, int index, vector<char>& vec)
    {
        if(index==digits.size()) 
        {
            result.emplace_back(vec.begin(), vec.end());
        }
        else
        {
            auto str = charVec[digits[index]-'2'];
            auto length = str.size();
            for(int i=0;i<length;i++)
            {
                vec.push_back(str[i]);
                search(digits,index+1,vec);
                vec.pop_back();
            }
        }
    }
    
    vector<string> letterCombinations(string digits) {
        if(digits.size()==0) return result;
        vector<char> vec;
        search(digits, 0, vec);
        return result;
    }
};