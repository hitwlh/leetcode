257_Binary_Tree_Paths


题目大意
Given a binary tree, return all root-to-leaf paths.

解决方案
这题感觉挺简单的，直接递归一个vector<vector<int>>函数就是了

样例
For example, given the following binary tree:

   1
 /   \
2     3
 \
  5
All root-to-leaf paths are:

["1->2->5", "1->3"]