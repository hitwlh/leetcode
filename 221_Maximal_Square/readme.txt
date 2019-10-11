221_Maximal_Square


题目大意
Given a 2D binary matrix filled with 0's and 1's, find the largest square containing only 1's and return its area.




解决方案
定义dp[i][j]表示以matrix[i][j]为右下角所能得到的最大的正方形。
则第0行和第0列直接拷贝就是了
从i=1, j=1开始
若matrix[i][j] == 0, 则dp[i][j] = 0;
若matrix[i][j] == 1, 则dp[i][j] = min(dp[i-1][j-1], dp[i-1][j], dp[i][j-1]) + 1

这个等式可以画图看出来，若min(dp[i-1][j-1], dp[i-1][j], dp[i][j-1]) == k，
说明dp[i-1][j-1]为右下角的最大矩形边长是k， dp[i-1][j]为右下角的最大矩形边长是k，dp[i][j-1]为右下角的最大矩形边长是k
并且matrix[i][j]也是1，所以dp[i][j]为右下角的最大矩形边长是k+1




样例
For example, given the following matrix:

1 0 1 0 0
1 0 1 1 1
1 1 1 1 1
1 0 0 1 0
Return 4.

