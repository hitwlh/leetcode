class MyStack {
public:
    /** Initialize your data structure here. */
    MyStack() {
        empt = 0;
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        q[empt].push(x);
        while(!q[1-empt].empty()){
            q[empt].push(q[1-empt].front());
            q[1-empt].pop();
        }
        empt = 1 - empt;
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int ret = q[1-empt].front();
        q[1-empt].pop();
        return ret;
    }
    
    /** Get the top element. */
    int top() {
        return q[1-empt].front();
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return q[1-empt].empty();
    }
private:
    queue<int> q[2];
    int empt;
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack obj = new MyStack();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.top();
 * bool param_4 = obj.empty();
 */