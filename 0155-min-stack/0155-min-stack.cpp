class MinStack {
public:
stack<int> st1, st2; // one stores in normal order other in minElement order
    MinStack() {}
    
    void push(int value) {
        st1.push(value);
        if(st2.empty() || value <= st2.top()) st2.push(value); // push it onlt if it really has minVal
    }
    
    void pop() {
        if(st1.top() == st2.top())  st2.pop(); // if minVal itself is stack top
        st1.pop();
    }
    
    int top() {
        return st1.empty() ? -1 : st1.top();
    }
    
    int getMin() {
        return st2.empty() ? -1 : st2.top();
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