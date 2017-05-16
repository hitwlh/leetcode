225_Implement_Stack_using_Queues


题目大意


解决方案
这题的解决方案挺简单的，不难想到也不难实现。就是记住效率确实没法全O(1)
solution1.cpp里存储的是一个队列，push: O(1)，pop: O(n)，top: O(n)的解法
一个队列的写法要注意pop的时候，如何识别最后一个元素，因为一旦pop queue一个元素，queue的size也短暂地-1了，会导致错误

solution2.cpp里存储的是2个队列，push: O(n)，pop: O(1)，top: O(1)的解法，也可以写成1个队列

样例


