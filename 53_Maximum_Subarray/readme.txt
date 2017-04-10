53_Maximum_Subarray


题目大意
Find the contiguous subarray within an array (containing at least one number) which has the largest sum.

解决方案
动态规划的解法，递推公式sum[i] = max(use_big[i], sum[i-1]);

样例
For example, given the array [-2,1,-3,4,-1,2,1,-5,4],
the contiguous subarray [4,-1,2,1] has the largest sum = 6.

