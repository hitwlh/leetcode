377_Combination_Sum_IV


题目大意
Given an integer array with all positive numbers and no duplicates, find the number of possible combinations that add up to a positive integer target.




解决方案
一开始我用递归的方法做，超时了。
也是怪这题没有写数据范围，如果知道数据范围其实还是相对不那么难想。
用一个dp数组，dp[i] = j表示用num里的数字拼成i一共有j种排列。
对于dp[x]，
对所有nums[i]<dp[x],dp[x]+=dp[x-nums[i]]
相当于把nums[i]放在头部





样例
Example:

nums = [1, 2, 3]
target = 4

The possible combination ways are:
(1, 1, 1, 1)
(1, 1, 2)
(1, 2, 1)
(1, 3)
(2, 1, 1)
(2, 2)
(3, 1)

Note that different sequences are counted as different combinations.

Therefore the output is 7.
Follow up:
What if negative numbers are allowed in the given array?
How does it change the problem?
What limitation we need to add to the question to allow negative numbers?

