103_Binary_Tree_Zigzag_Level_Order_Traversal


题目大意
Given a binary tree, return the zigzag level order traversal of its nodes' values. (ie, from left to right, then right to left for the next level and alternate between).

解决方案
这题就是层序遍历而已。
但是要写一遍ac的code是很不容易的！！！一定要细心，而且逻辑要理通顺！！

    3
   / \
末 9  20  <-
    /  \
-> 15   7 末
看到了吗，两个末字，也就是说每层遍历的起点都是vector的末尾，really important！


样例
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its zigzag level order traversal as:
[
  [3],
  [20,9],
  [15,7]
]

