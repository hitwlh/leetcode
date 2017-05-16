198_House_Robber


题目大意
You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security system connected and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of money you can rob tonight without alerting the police.

解决方案
题目翻译：给出一系列数，从里面挑一些出来，使和最大，要求挑的数没有相邻的。
显然动态规划。我的做法在
solution1.cpp，递推公式是dp[i][j] = max(dp[i][k-2]+dp[k][k]+ dp[k+2][j]),for i<=k<=j
但是这个做法效率不是很高。
网上的解法在solution2.cpp
递推公式是
money[i][0] = max(money[i - 1][0], money[i - 1][1]) 
上述公式表示，不偷第 i 家房子，当前最大收益就是前一家房子的最大收益，前一家房子可能被偷了，也可能没有被偷。 
money[i][1] = money[i - 1][0] + nums[i] 
上述公式表示，要偷第 i 家的房子，必须在不偷第 i-1 家房子的前提下，才能加上偷第 i 家获得的收益。

样例


