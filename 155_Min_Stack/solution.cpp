class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
        ;
    }
    
    void push(int x) {
        sta1.push(x);
        if(!sta2.empty())
            sta2.push(min(sta2.top(), x));
        else sta2.push(x);
    }
    
    void pop() {
        sta1.pop();
        sta2.pop();
    }
    
    int top() {
        return sta1.top();
    }
    
    int getMin() {
        return sta2.top();
    }
private:
    stack<int> sta1, sta2;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */