95_Unique_Binary_Search_Trees_II


题目大意
Given an integer n, generate all structurally unique BST's (binary search trees) that store values 1...n.

解决方案
用递归的方法。get_tree(int left, int right)，遍历[left,right]，选择一个点作为root，然后root左边和右边的区间分别进行get_tree(int left, int right)，将左右返回的结果相结合就是了

样例
For example,
Given n = 3, your program should return all 5 unique BST's shown below.

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3

