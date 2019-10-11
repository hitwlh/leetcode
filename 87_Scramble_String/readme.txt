87_Scramble_String


题目大意
Given a string s1, we may represent it as a binary tree by partitioning it to two non-empty substrings recursively.


这道题定义了一种爬行字符串，就是说假如把一个字符串当做一个二叉树的根，然后它的非空子字符串是它的子节点，然后交换某个子字符串的两个子节点，重新爬行回去形成一个新的字符串

解决方案
https://www.tianmaying.com/tutorial/LC87
http://blog.csdn.net/sxingming/article/details/51824434

注意：great、rgeat、rgtae...都是great的Scramble String

如果给great找它的Scramble String，需要就是找到一个切割点(任意)，然后
1. 产生两种串，一种是调换左右，一种是不动
2. 对上一步产生的串的左侧、右侧分别递归调用本过程



分治
这题立马就想到用递归，但是简单的递归会超时，要进行剪枝
(分治+剪枝)
剪枝的策略是先sort，sort完后如果相等就去递归处理左右，如果不相等就不用了，直接失败
这个答案在solution1.cpp


动态规划(分治+记录)
scramble(l, i, j，表示“s1从位置i开始长度为l的子串”能否经由scramble操作变为“s2从位置j开始长度为l的子串”，而我们要求的答案就是scramble(n, 0, 0)
然后动规填表
显然这个的空间复杂度是O(N^3)，往表里填一个元素的时间复杂度是O(N)，总的时间复杂度是O(N^4)
这个答案在solution2.cpp


样例
Below is one possible representation of s1 = "great":

    great
   /    \
  gr    eat
 / \    /  \
g   r  e   at
           / \
          a   t
To scramble the string, we may choose any non-leaf node and swap its two children.

For example, if we choose the node "gr" and swap its two children, it produces a scrambled string "rgeat".

    rgeat
   /    \
  rg    eat
 / \    /  \
r   g  e   at
           / \
          a   t
We say that "rgeat" is a scrambled string of "great".

Similarly, if we continue to swap the children of nodes "eat" and "at", it produces a scrambled string "rgtae".

    rgtae
   /    \
  rg    tae
 / \    /  \
r   g  ta  e
       / \
      t   a
We say that "rgtae" is a scrambled string of "great".

Given two strings s1 and s2 of the same length, determine if s2 is a scrambled string of s1.

