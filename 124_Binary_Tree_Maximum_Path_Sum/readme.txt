124_Binary_Tree_Maximum_Path_Sum


题目大意
Given a binary tree, find the maximum path sum.
For this problem, a path is defined as any sequence of nodes from some starting node to any node in the tree along the parent-child connections. The path must contain at least one node and does not need to go through the root.

解决方案
我最开始想到的思路是O(N^3)的，就是先计算每个点到root的路径的和，然后随意挑两个点作为起点和终点，然后找到其最低公共祖先，在根据这三个点进行算术运算可直接得到这条路径的和，但是找到其最低公共祖先的时间代价是O(N)，所以总的时间复杂度是O(N^3)
网上看到的解法：
处理root的时候，计算出root->left为根的最大路径以及以root->right为根的最大路径。
如果，root->left为根(不能分叉)的最大路径>0，可以将它和root->val相加
如果，root->right为根(不能分叉)的最大路径>0，可以将它和root->val相加
加得的结果就是以root为根所能获得的最大路径的长度，将它和ret比较

样例
For example:
Given the below binary tree,

       1
      / \
     2   3
Return 6.

