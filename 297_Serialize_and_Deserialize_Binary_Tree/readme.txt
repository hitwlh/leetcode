297_Serialize_and_Deserialize_Binary_Tree


题目大意
Serialization is the process of converting a data structure or object into a sequence of bits so that it can be stored in a file or memory buffer, or transmitted across a network connection link to be reconstructed later in the same or another computer environment.

Design an algorithm to serialize and deserialize a binary tree. There is no restriction on how your serialization/deserialization algorithm should work. You just need to ensure that a binary tree can be serialized to a string and this string can be deserialized to the original tree structure.

解决方案
是449题的进阶版本，449题给的是bst树，这题无序。因此bst的先根方式就行不通了。
直接用449题的solution1.cpp就好了，每次在开头标识出根的存储下标，代码在solution.cpp

看了网上的解法，有用层序遍历的，层序遍历就相当于leetcode表示图的那种序列化方式就ok了
解法在http://blog.csdn.net/ljiabin/article/details/49474445
但是这个非常不好写，因为这不是一棵满二叉树，因此并不能父亲节点i，左右儿子分别是2*i+1 和 2*i+2。这种解法貌似挺麻烦的，没看

另一种解法是用先根遍历，一直往左。这样一直往左写，写不动了就往父亲的右儿子写
需要注意的是这里要用string的引用，因为左儿子要去删除序列。
solution1.cpp


样例


