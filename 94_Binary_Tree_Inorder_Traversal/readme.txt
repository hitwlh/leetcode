94_Binary_Tree_Inorder_Traversal


题目大意
Given a binary tree, return the inorder traversal of its nodes' values.

解决方案
递归的解法自然不用多说了。
非递归解法是用一个栈，既然是中根，那么在栈中：根左子树在根上面，所以压栈时先压当前节点，然后当前节点进入左儿子
如果当前节点为空，则弹栈并读取值，然后将右儿子入栈，当前节点进入右儿子

样例
Given binary tree [1,null,2,3],
   1
    \
     2
    /
   3
return [1,3,2].