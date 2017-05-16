530_Minimum_Absolute_Difference_in_BST


题目大意
Given a binary search tree with non-negative values, find the minimum absolute difference between values of any two nodes.



解决方案
二叉搜索树相差最小的两个node，直接中序遍历一下然后找最小的差距就行了

样例
Example:

Input:

   1
    \
     3
    /
   2

Output:
1

Explanation:
The minimum absolute difference is 1, which is the difference between 2 and 1 (or between 2 and 3).

