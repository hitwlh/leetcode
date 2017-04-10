101_Symmetric_Tree


题目大意
Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

解决方案
先根比较一下就是了，比较的时候不是简单“左对左右对右”而是“左对右右对左”

样例
For example, this binary tree [1,2,2,3,4,4,3] is symmetric:

    1
   / \
  2   2
 / \ / \
3  4 4  3
But the following [1,2,2,null,3,null,3] is not:
    1
   / \
  2   2
   \   \
   3    3

