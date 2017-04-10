110_Balanced_Binary_Tree


题目大意
Given a binary tree, determine if it is height-balanced.
For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.

解决方案
递归左边和右边，返回左右的深度，判断左右深度是否最大差1，同时用一个全局变量保存左右是否不是平衡二叉树

样例


