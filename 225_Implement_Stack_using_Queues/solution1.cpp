class MyStack {
public:
    /** Initialize your data structure here. */
    MyStack() {
        ;
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        myque.push(x);
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        for(int i = 0; i + 1 < myque.size(); i++){
            int tmp = myque.front();
            myque.pop();
            myque.push(tmp);
        }
        int tmp = myque.front();
        myque.pop();
        return tmp;
    }
    
    /** Get the top element. */
    int top() {
        int tmp;
        for(int i = 0; i < myque.size(); i++){
            tmp = myque.front();
            myque.pop();
            myque.push(tmp);
        }
        return tmp;
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return myque.size() == 0;
    }
private:
    queue<int> myque;
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack obj = new MyStack();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.top();
 * bool param_4 = obj.empty();
 */