class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> stk;
        int length = s.size();
        int maxLength=0;
        int l=0;
        for(int i=0;i<length;i++)
        {
            if(s[i]=='(') stk.push(i);
            else
            {
                if(stk.empty()) {stk.push(i);}
                else
                {
                    if(s[stk.top()]=='(') {stk.pop();}
                    else{stk.push(i);}
                }
            }
        }
        // After the scan is done, the stack will only contain the indices of characters which cannot be matched
        if(stk.empty()) return length;
        else
        {
            int a = length,b=0;
            while(!stk.empty())
            {
                b = stk.top();stk.pop();
                maxLength = max(maxLength,a-b-1);
                a=b;
            }
            maxLength = max(maxLength,a);
            return maxLength;
        }
    }
};