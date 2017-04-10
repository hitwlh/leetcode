96_Unique_Binary_Search_Trees


题目大意
Given n, how many structurally unique BST's (binary search trees) that store values 1...n?



解决方案
这种题最关键的是如何考虑递归函数。在ret[i]中存储i个节点的unique BST的数目，那么求ret[k]时，根可以从0取到k，所以一侧字树的结点数至少为0个至多为k-1个，需要for循环处理从0到k-1

样例
Given n = 3, there are a total of 5 unique BST's.

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3

