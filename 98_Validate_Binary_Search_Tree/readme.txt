98_Validate_Binary_Search_Tree


题目大意
Given a binary tree, determine if it is a valid binary search tree (BST).

解决方案
中根遍历一下，如果是Binary tree会得到一个递增的序列

样例
Example 1:
    2
   / \
  1   3
Binary tree [2,1,3], return true.
Example 2:
    1
   / \
  2   3
Binary tree [1,2,3], return false.

