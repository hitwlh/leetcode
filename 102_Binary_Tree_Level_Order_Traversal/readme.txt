102_Binary_Tree_Level_Order_Traversal


题目大意
Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).

解决方案
把每层的儿子放到队列里，最后放一个null判断当前层结束

样例
For example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its level order traversal as:
[
  [3],
  [9,20],
  [15,7]
]

