105_Construct_Binary_Tree_from_Preorder_and_Inorder_Traversal


题目大意
Given preorder and inorder traversal of a tree, construct the binary tree.
Note:
You may assume that duplicates do not exist in the tree.


解决方案
先根：xB0...BmC0...Cn
中根：B0...BmxC0...Cn
先跟第一个字符就是根，在中跟中找到它，然后建立root
在中跟中x左边的字符就是左子树的中跟序列，同时知道m的大小，在先跟中x右边m+1个字符就是左子树的先根序列
在中跟中x右边的字符就是右子树的中跟序列，在先跟中Bm右边的字符就是右子树的先根序列
因此递归建立左、右子树就行了

样例


