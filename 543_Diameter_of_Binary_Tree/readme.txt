543_Diameter_of_Binary_Tree


题目大意
Given a binary tree, you need to compute the length of the diameter of the tree. The diameter of a binary tree is the length of the longest path between any two nodes in a tree. This path may or may not pass through the root.

解决方案
用dfs
int left = dfs(root->left);
int right = dfs(root->right);
if(left+right+1 > MAX) MAX = left+right+1;
return max(left, right) + 1;

样例
Example:
Given a binary tree 
          1
         / \
        2   3
       / \     
      4   5    
Return 3, which is the length of the path [4,2,1,3] or [5,2,1,3].

