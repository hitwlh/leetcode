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

解决方案
solution的解法不是我现在想的，solution的解法是一个道理，但是那样写比较容易写错
我现在想的是直接维护一个队列，队列里是某一层的结果，最后添加null

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
