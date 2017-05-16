232_Implement_Queue_using_Stacks


题目大意
Implement the following operations of a queue using stacks.

push(x) -- Push element x to the back of queue.
pop() -- Removes the element from in front of queue.
peek() -- Get the front element.
empty() -- Return whether the queue is empty.

Notes:
You must use only standard operations of a stack -- which means only push to top, peek/pop from top, size, and is empty operations are valid.
Depending on your language, stack may not be supported natively. You may simulate a stack by using a list or deque (double-ended queue), as long as you use only standard operations of a stack.
You may assume that all operations are valid (for example, no pop or peek operations will be called on an empty queue).





解决方案
双栈法，用sta[0]保存push的内容。
如果要pop，把sta[1]做pop，如果sta[1]空，就先把sta[0]的元素全都pop到sta[1]里去

样例


