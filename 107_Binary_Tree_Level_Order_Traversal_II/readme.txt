107_Binary_Tree_Level_Order_Traversal_II


题目大意
Given a binary tree, return the bottom-up level order traversal of its nodes' values. (ie, from left to right, level by level from leaf to root).

解决方案
和105一样，就是最后翻转一下就是了。
或者插入的时候由从尾插改为从头插

样例
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its bottom-up level order traversal as:
[
  [15,7],
  [9,20],
  [3]
]

