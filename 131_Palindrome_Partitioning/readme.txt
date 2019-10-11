131_Palindrome_Partitioning


题目大意
Given a string s, partition s such that every substring of the partition is a palindrome.
Return all possible palindrome partitioning of s.

把一个字符串切分成若干个子串，每个都是回文串，找到所有的partition方案


解决方案
以my_s[0]为起点，往右找所有回文串，找到的话递归调用右侧的串。见solution1.cpp
但是可能会有重复计算，比如
my_s[0] my_s[1] my_s[2] my_s[3...end]
my_s[0, 1] my_s[2] my_s[3...end]
这里2为起点和3为起点都调用多次

所以我自己实现的其实是solution2.cpp 加上flag和ret数组
flag[i] == true 表示已经划分过以my_s[i]为起点的串
ret[i] 表示以my_s[i]为起点的串的划分结果


solution3.cpp
从右往左看，这样就不需要递归调用

样例
For example, given s = "aab",
Return

[
  ["aa","b"],
  ["a","a","b"]
]