class Solution {
public:
    
    int evalRPN(vector<string>& tokens) {
        stack<int> stk;
        for(int i=0;i<tokens.size();i++)
        {
            if(tokens[i]=="+")
            {
                int op2 = stk.top();
                stk.pop();
                int op1 = stk.top();
                stk.pop();
                stk.push(op1+op2);
            }
            else if(tokens[i]=="-")
            {
                int op2 = stk.top();
                stk.pop();
                int op1 = stk.top();
                stk.pop();
                stk.push(op1-op2);   
            }
            else if(tokens[i]=="*")
            {
                int op2 = stk.top();
                stk.pop();
                int op1 = stk.top();
                stk.pop();
                stk.push(op1*op2);
            }
            else if(tokens[i]=="/")
            {
                int op2 = stk.top();
                stk.pop();
                int op1 = stk.top();
                stk.pop();
                stk.push(op1/op2);
            }
            else
            {
                stk.push(stoi(tokens[i]));
            }
        }
        return stk.top();
    }
};