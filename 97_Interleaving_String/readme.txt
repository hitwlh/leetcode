97_Interleaving_String


题目大意
Given s1, s2, s3, find whether s3 is formed by the interleaving of s1 and s2.


解决方案
如果想暴力递归做的话，会超时

这里用到的解决方案是动态规划。定义dp[i][j]代表s1.substr(0,i)和s2.substr(0,j)能否组成s3.substr(0, i + j)
定义好dp之后算法就挺简单了
还有一个重点是要注意如何初始化

样例
For example,
Given:
s1 = "aabcc",
s2 = "dbbca",

When s3 = "aadbbcbcac", return true.
When s3 = "aadbbbaccc", return false.

