494_Target_Sum


题目大意
You are given a list of non-negative integers, a1, a2, ..., an, and a target, S. Now you have 2 symbols + and -. For each integer, you should choose one from + and - as its new symbol.

Find out how many ways to assign symbols to make sum of integers equal to target S.
Note:
The length of the given array is positive and will not exceed 20.
The sum of elements in the given array will not exceed 1000.
Your output answer is guaranteed to be fitted in a 32-bit integer.




解决方案
这题最简单的就是暴力穷搜,solution1.cpp，没有需要注意的点

第2种解法是动态规划。
参考
http://tianshilei.me/2017/02/10/leetcode494/
http://blog.csdn.net/hit0803107/article/details/54894227

给序列里面的每个元素分配一个符号，使得最后的和等于目标值，那实际上不就变成我们从给定序列中找两个子集 P 和 N，使得 sum(P) - sum(N) = S （集合P里的元素分配+， 集合N里的元素分配-）且 P + N = nums 了吗？化简一点就是我们需要找到一个集合 P，使得 sum(P) = S - sum(nums - P)。那我们是不是每次需要求出 sum(P) 和 sum(nums - P) 呢？其实不然，我们考虑化简 sum(P) - sum(N) = S：
sum(P) - sum(N) = S
sum(P) + sum(N) + sum(P) - sum(N) = S + sum(P) + sum(N)
2 * sum(P) = S + sum(nums)
sum(P) = (S + sum(nums)) / 2
也就是说，我们只需要找到一个集合 P，使得 sum(P) 等于 (S + sum(nums)) / 2 即可
S + sum(nums)是常数

设target =  (S + sum(nums)) / 2
定义dp[0...target]数组
dp[i]表示和为i的集合有多少个
for(int i = target; i >= n; i--)
那么dp[i] = dp[i] + dp[i-n];

详细代码见solution2.cpp





样例
Example 1:
Input: nums is [1, 1, 1, 1, 1], S is 3. 
Output: 5
Explanation: 

-1+1+1+1+1 = 3
+1-1+1+1+1 = 3
+1+1-1+1+1 = 3
+1+1+1-1+1 = 3
+1+1+1+1-1 = 3

There are 5 ways to assign symbols to make the sum of nums be target 3.

