449_Serialize_and_Deserialize_BST


题目大意
Serialization is the process of converting a data structure or object into a sequence of bits so that it can be stored in a file or memory buffer, or transmitted across a network connection link to be reconstructed later in the same or another computer environment.

Design an algorithm to serialize and deserialize a binary search tree. There is no restriction on how your serialization/deserialization algorithm should work. You just need to ensure that a binary search tree can be serialized to a string and this string can be deserialized to the original tree structure.

The encoded string should be as compact as possible.
Note: Do not use class member/global/static variables to store states. Your serialize and deserialize algorithms should be stateless.



解决方案
这题是要把一棵BST树转化成string，然后将string转化成BST树
第一个要点就是int和string的互换，同时也就知道了要增加分隔符
我想到的方案是在中根遍历得到序列，同时在string头增加一个int变量，这个int变量是left树的string的长度，因此处理一个字串的时候，根据头部信息就可以在常量时间内找到root的位置、左子树的串、右子树的串 solution1.cpp

网上的解法是用先根遍历，这样字串头就是根，然后往后遍历，比它小的就是左，比它大的就是右
solution2.cpp

这两种代码实际运行时间没太大区别


样例


