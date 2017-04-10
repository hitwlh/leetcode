404_Sum_of_Left_Leaves


题目大意
Find the sum of all left leaves in a given binary tree.

解决方案
用递归的方式做，添加一个是否在左边的flag，如果flag为true并且是叶子，则可以加，否则不能加



样例
    3
   / \
  9  20
    /  \
   15   7

There are two left leaves in the binary tree, with values 9 and 15 respectively. Return 24.




