230_Kth_Smallest_Element_in_a_BST


题目大意
Given a binary search tree, write a function kthSmallest to find the kth smallest element in it.

Note: 
You may assume k is always valid, 1 ? k ? BST's total elements.

Follow up:
What if the BST is modified (insert/delete operations) often and you need to find the kth smallest frequently? How would you optimize the kthSmallest routine?



解决方案
这题挺简单的，测试数据也很弱。
可以直接中根遍历整张图，然后找第k个，或者改进点，遍历的时候遍历到第k个了就停止遍历
或者用二叉搜索，递归进入左、右
solution.cpp里保存的是二叉搜索的解法

样例


