331_Verify_Preorder_Serialization_of_a_Binary_Tree


题目大意
One way to serialize a binary tree is to use pre-order traversal. When we encounter a non-null node, we record the node's value. If it is a null node, we record using a sentinel value such as #.

     _9_
    /   \
   3     2
  / \   / \
 4   1  #  6
/ \ / \   / \
# # # #   # #
For example, the above binary tree can be serialized to the string "9,3,4,#,#,1,#,#,2,#,6,#,#", where # represents a null node.

Given a string of comma separated values, verify whether it is a correct preorder traversal serialization of a binary tree. Find an algorithm without reconstructing the tree.

Each comma separated value in the string must be either an integer or a character '#' representing null pointer.

You may assume that the input format is always valid, for example it could never contain two consecutive commas such as "1,,3".

给了我们一个类似序列化二叉树后的字符串，让我们判断给定是字符串是不是一个正确的序列化的二叉树的字符串。



解决方案
1. 用一个栈存储，每次将当前字符压栈，然后看栈顶是否有2个连着的终止符号，如果有，则一共弹出3个元素（如果弹不出3个元素，就报错）然后压入一个终止符号,并反复处理直到没有如果没有，处理下一个字符。

2. 可以直接用一个变量保存，不用栈。变量保存的是在树里当前能写字符的位置有多少。因此，如果想写一个字符，必须确保还有位置可写，写进去后，如果是树叶，那就可以了，如果是内结点，那又增加了两个可写的位置。
处理过程中，必须有位置可写，否则返回false，处理完所有字符之后，必须没有位置可写了，否则返回false。



样例


