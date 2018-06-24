class MinStack {
public:
    /** initialize your data structure here. */
    stack<int> stk;
    stack<int> stk2;
    MinStack() {
    }
    
    void push(int x) {
        stk.push(x);
        if(stk2.empty() || x<=stk2.top()) stk2.push(x);
    }
    
    void pop() {
        if(stk.top()>stk2.top()) stk.pop();
        else
        {
            stk.pop();
            stk2.pop();
        }
    }
    
    int top() {
        return stk.top();
    }
    
    int getMin() {
        return stk2.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */