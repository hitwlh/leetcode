116_Populating_Next_Right_Pointers_in_Each_Node


题目大意
Given a binary tree

    struct TreeLinkNode {
      TreeLinkNode *left;
      TreeLinkNode *right;
      TreeLinkNode *next;
    }
Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.

Initially, all next pointers are set to NULL.

Note:

You may only use constant extra space.
You may assume that it is a perfect binary tree (ie, all leaves are at the same level, and every parent has two children).

解决方案
1. 层序遍历，并且在每层末尾往push一个NULL，solution1.cpp
2. 递归，根据当前层设置下一层，然后找到下一层起点，递归处理， solution2.cpp

solution.cpp里保存的是最初的解法，有点像递归的算法但是用非递归实现
注意这题题意要求常量空间，那就只能用递归解法了(事实上递归解法的栈也不是常量大小的！！！)


样例
For example,
Given the following perfect binary tree,
         1
       /  \
      2    3
     / \  / \
    4  5  6  7
After calling your function, the tree should look like:
         1 -> NULL
       /  \
      2 -> 3 -> NULL
     / \  / \
    4->5->6->7 -> NULL
