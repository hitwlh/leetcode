145_Binary_Tree_Postorder_Traversal


题目大意
Given a binary tree, return the postorder traversal of its nodes' values.



解决方案
递归方法自不必说
非递归方法：双栈，先把root入栈1，然后while栈1非空，弹出栈顶，将其左儿子右儿子依次入栈1，将其自身入栈2
依次弹出栈2即可


样例

Given binary tree {1,#,2,3},
   1
    \
     2
    /
   3
return [3,2,1].