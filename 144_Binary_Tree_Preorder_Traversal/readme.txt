144_Binary_Tree_Preorder_Traversal


题目大意
Given a binary tree, return the preorder traversal of its nodes' values.
先根遍历

解决方案
递归版本不用说了非常简单
非递归版本要用栈而不是队列。
先把root入栈，然后只要栈非空，那就取栈顶并且获取其value，然后右儿子左儿子依次入栈，

样例


