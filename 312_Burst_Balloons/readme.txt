312_Burst_Balloons


题目大意
Given n balloons, indexed from 0 to n-1. Each balloon is painted with a number on it represented by array nums. You are asked to burst all the balloons. If the you burst balloon i you will get nums[left] * nums[i] * nums[right] coins. Here left and right are adjacent indices of i. After the burst, the left and right then becomes adjacent.

Find the maximum coins you can collect by bursting the balloons wisely.

Note: 
(1) You may imagine nums[-1] = nums[n] = 1. They are not real therefore you can not burst them.
(2) 0 ≤ n ≤ 500, 0 ≤ nums[i] ≤ 100



解决方案
这题我一开始想到了要定义dp[i][j]表示从s[i]到s[j]的最优解，并且按照长度从1...n来计算dp[i][j]，但是我的递推公式写错了
正确的递推公式是：
dp[i][j] = max(dp[i][j], nums[i - 1]*nums[k]*nums[j + 1] + dp[i][k - 1] + dp[k + 1][j])  ( i ≤ k ≤ j )
主要注意的是nums的连乘，

我开始以为是nums[k - 1]*nums[k]*nums[k + 1]
事实上这样就大错特错了，因为假设dp[i][k - 1]和dp[k + 1][j]都是正确的，那么dp[i][k-1]计算完后应该s[i]...s[k-1]都被删掉了，同理dp[k+1][j]计算完后s[k+1]...s[j]都被删除掉了，那么s[k]应该和s[i-1]以及s[j+1]连乘才对

知道这个递推公式之后再注意一下边界条件就是了。蛮不错的这题。

样例
Example:
Given [3, 1, 5, 8]
Return 167

nums = [3,1,5,8] --> [3,5,8] -->   [3,8]   -->  [8]  --> []
coins =  3*1*5      +  3*5*8    +  1*3*8      + 1*8*1   = 167

