173_Binary_Search_Tree_Iterator


题目大意
Implement an iterator over a binary search tree (BST). Your iterator will be initialized with the root node of a BST.

Calling next() will return the next smallest number in the BST.

Note: next() and hasNext() should run in average O(1) time and uses O(h) memory, where h is the height of the tree.

解决方案
1. 就是用bst来实现一个类，要万分注意的是next相当于要返回下一个值，同时要删掉！！！因为不可能一直next同一个数！！！
2. 用一个栈，非递归地实现。蛮有意思的！！！
样例


