115_Distinct_Subsequences


题目大意
Given a string S and a string T, count the number of distinct subsequences of S which equals T.

A subsequence of a string is a new string which is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (ie, "ACE" is a subsequence of "ABCDE" while "AEC" is not).




解决方案
这题写的难度是hard，但是只要想到了动规的思路，代码并不难写。
定义vector<vector<int>> dp(2, vector<int>(s.length(), 0));
每一轮更新dp[SWAP]数组
从右向左一一比较。
dp定义了两个一维数组dp[0] dp[1]，因为每轮更新完成之后，要把旧的值改为全零，如果不定义两个数组，那更新完后，想去把旧值抹为9时，区分不开哪个数据是新的哪个是旧的
dp[][j]保留的是s.substr(j)与t.substr(i)相匹配时有多少种匹配方案
j从后往前计算，计算到s.substr(0)时，就知道了s与t.substr(i)有多少匹配方案。
再把i往左移动一位，从右往左找s[j]==t[i]，找到的时候更新dp[][j] = sum(dp[][j+1],dp[][j+1]...dp[][s.length()-1])







样例
Here is an example:
S = "rabbbit", T = "rabbit"

Return 3.

