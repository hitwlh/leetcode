410_Split_Array_Largest_Sum


题目大意
Given an array which consists of non-negative integers and an integer m, you can split the array into m non-empty continuous subarrays. Write an algorithm to minimize the largest sum among these m subarrays.

Note:
If n is the length of array, assume the following constraints are satisfied:

1 ≤ n ≤ 1000
1 ≤ m ≤ min(50, n)



翻译：将一个数组切割为m个子数组，令所有子数组和的最大值最小，求这个最小的最大值是多少。

解决方案

solution1.cpp 很难想到，但是很好写。
显然，分为n份是最大值就是max(每个元素都是一个子数组)，分为1份时最大值是数组和sum
令L = max， R = sum
则答案介于[L, R]之间，然后再二分。
对于mid = L + (R - L) / 2; 即如果子array和最大值最小是mid，则可以从头到尾划分一下数组，获得use，也就是说如果给定子数组和的最大值最小是mid，需要将原数组划分为use份。
如果use>m，说明mid太小了。if(use > m) L = mid + 1;
最后返回L


solution2.cpp 不难想到，但是代码不好写
dp[i][j]表示前j个数分为i组时的解。
则求dp[i][j]的时候，枚举最后一组：
dp[i][j] = min{max(dp[i-1][k-1], sum[j-1] - sum[k] + nums[k])} 0<=k<=j-1

one-time-attention
1. 代码里要注意max(dp[i-1][k], sum[j-1] - sum[k] + nums[k]
dp[i-1][k]是表示0, 1, ..., k-1
如果用dp[i-1][k-1]，就是0, 1, ..., k-2，那就错了

2. 所有都改成long



样例
Examples:

Input:
nums = [7,2,5,10,8]
m = 2

Output:
18

Explanation:
There are four ways to split nums into two subarrays.
The best way is to split it into [7,2,5] and [10,8],
where the largest sum among the two subarrays is only 18.

