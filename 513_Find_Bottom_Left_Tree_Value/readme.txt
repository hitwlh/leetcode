513_Find_Bottom_Left_Tree_Value


题目大意
Given a binary tree, find the leftmost value in the last row of the tree.

解决方案
和515. Find Largest Value in Each Tree Row很像，那题是要找到每层的最大元素，这题是要找每层的起始元素。
直接粘贴了那题的大部分代码


solution2.cpp
dfs
//每次优先向左走，然后看当前到的地方是否是新的一层，level_left是每一层的最左结点
样例

Example 1:
Input:

    2
   / \
  1   3

Output:
1
Example 2: 
Input:

        1
       / \
      2   3
     /   / \
    4   5   6
       /
      7

Output:
7

