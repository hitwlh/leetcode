113_Path_Sum_II


题目大意
Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.

解决方案
和112类似，就是不能直接返回bool，而是要在每个节点都保留到当前节点的整个路径，然后往下传，如果下面是正确的，那就把结果放到返回vector里，否则直接丢弃

样例


For example:
Given the below binary tree and sum = 22,
              5
             / \
            4   8
           /   / \
          11  13  4
         /  \    / \
        7    2  5   1
return
[
   [5,4,11,2],
   [5,8,4,5]
]