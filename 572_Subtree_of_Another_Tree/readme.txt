572_Subtree_of_Another_Tree


题目大意
Given two non-empty binary trees s and t, check whether tree t has exactly the same structure and node values with a subtree of s. A subtree of s is a tree consists of a node in s and all of this node's descendants. The tree s could also be considered as a subtree of itself.





解决方案
将这棵树序列化，然后对比是否存在子序列来判断是否存在子树。

叶子节点要用",,"
非叶子结点：
str[w] += "," + to_string(s->val);
str[w] += "," + to_string(s->val) + ",";
str[w] += to_string(s->val) + ",";
前两种方式可以，第三种不行。考虑输入
[12]
[2]
第三种会转化成"12,,,,,"、"2,,,,,"，导致失败。2是12的后缀！



样例
Example 1:
Given tree s:

     3
    / \
   4   5
  / \
 1   2
Given tree t:
   4 
  / \
 1   2
Return true, because t has the same structure and node values with a subtree of s.
Example 2:
Given tree s:

     3
    / \
   4   5
  / \
 1   2
    /
   0
Given tree t:
   4
  / \
 1   2
Return false.

