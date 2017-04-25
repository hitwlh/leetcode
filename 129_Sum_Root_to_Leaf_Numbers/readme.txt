129_Sum_Root_to_Leaf_Numbers


题目大意
Given a binary tree containing digits from 0-9 only, each root-to-leaf path could represent a number.

An example is the root-to-leaf path 1->2->3 which represents the number 123.

Find the total sum of all root-to-leaf numbers.

解决方案
简单的深搜，如果当前点不是叶子，若左儿子不空，就更新value后递归左儿子，左儿子结束后还原value的值，同样处理右儿子

样例


For example,

    1
   / \
  2   3
The root-to-leaf path 1->2 represents the number 12.
The root-to-leaf path 1->3 represents the number 13.

Return the sum = 12 + 13 = 25.
