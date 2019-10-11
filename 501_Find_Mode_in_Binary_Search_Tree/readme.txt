501_Find_Mode_in_Binary_Search_Tree


题目大意
Given a binary search tree (BST) with duplicates, find all the mode(s) (the most frequently occurred element) in the given BST.
Assume a BST is defined as follows:
The left subtree of a node contains only nodes with keys less than or equal to the node's key.
The right subtree of a node contains only nodes with keys greater than or equal to the node's key.
Both the left and right subtrees must also be binary search trees.


找二分搜索数的众数


解决方案
中根遍历一下得到递增序列，然后遍历找重复次数最大的就是了


样例

For example:
Given BST [1,null,2,2],
   1
    \
     2
    /
   2
return [2].
