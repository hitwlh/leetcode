538_Convert_BST_to_Greater_Tree


题目大意
Given a Binary Search Tree (BST), convert it to a Greater Tree such that every key of the original BST is changed to the original key plus sum of all keys greater than the original key in BST.

解决方案
就是中根遍历一下，得到顺序序列，然后从后往前叠加就是了

样例
Example:

Input: The root of a Binary Search Tree like this:
              5
            /   \
           2     13

Output: The root of a Greater Tree like this:
             18
            /   \
          20     13

