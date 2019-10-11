199_Binary_Tree_Right_Side_View


题目大意
Given a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.


解决方案
这题注意不能直接看一边，而是要层序遍历，每次入队NULL，就知道这层到最后了
比如像下面这样的，第二层看到的在root右边，第三层看到的的就在root左边了
   1            <---
 /   \
2     3         <---
 \      
  5             <---


样例
   1            <---
 /   \
2     3         <---
 \     \
  5     4       <---
You should return [1, 3, 4].

