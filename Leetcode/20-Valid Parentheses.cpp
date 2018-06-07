class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        int length = s.size();
        for(int i=0;i<length;i++)
        {
            auto ch = s[i];
            if(ch=='(' || ch== '[' || ch=='{')
            {
                switch(ch)
                {
                    case '(':stk.push(')');break;
                    case '[':stk.push(']');break;
                    case '{':stk.push('}');break;
                }
            }
            else
            {
                if(stk.empty() || stk.top()!=ch)
                {
                    return false;
                }
                else stk.pop();
            }
        }
        return stk.empty();
    }
};