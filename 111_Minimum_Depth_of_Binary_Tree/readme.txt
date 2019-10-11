111_Minimum_Depth_of_Binary_Tree


题目大意
Given a binary tree, find its minimum depth.
The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.

二叉树的经典问题之最小深度

解决方案
递归看左边和右边就是了。
Really important:如果一边返回的是0，说明那边没有叶子，不能用那边

样例


