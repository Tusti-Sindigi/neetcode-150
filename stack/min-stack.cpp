#include <stack>
using namespace std;

class MinStack {
public:

    stack<int> stk;
    stack<int> min_stk;

    MinStack() 
    {
        
    }
    
    void push(int value) 
    {
        stk.push(value);
        value=min(value, min_stk.empty()? value : min_stk.top());
        min_stk.push(value);
    }
    
    void pop() 
    {
        stk.pop();
        min_stk.pop();
    }
    
    int top() 
    {
        return stk.top();
    }
    
    int getMin() 
    {
        return min_stk.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */