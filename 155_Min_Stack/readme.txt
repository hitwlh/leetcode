155_Min_Stack


题目大意
Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.
push(x) -- Push element x onto stack.
pop() -- Removes the element on top of the stack.
top() -- Get the top element.
getMin() -- Retrieve the minimum element in the stack.




解决方案
用另外一个stack来保存最小值就是了
one-time-attention
push的时候不能写成
sta1.push(x);
sta2.push(min(sta2.top(), x));
而应该是
sta1.push(x);
if(!sta2.empty())
    sta2.push(min(sta2.top(), x));
else sta2.push(x);
因为如果sta2空的话根本就不能做top操作



样例
Example:
MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.getMin();   --> Returns -3.
minStack.pop();
minStack.top();      --> Returns 0.
minStack.getMin();   --> Returns -2.

