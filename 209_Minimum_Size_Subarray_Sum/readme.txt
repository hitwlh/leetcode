209_Minimum_Size_Subarray_Sum


题目大意
Given an array of n positive integers and a positive integer s, find the minimal length of a contiguous subarray of which the sum ≥ s. If there isn't one, return 0 instead.

For example, given the array [2,3,1,2,4,3] and s = 7,
the subarray [4,3] has the minimal length under the problem constraint.

More practice:
If you have figured out the O(n) solution, try coding another solution of which the time complexity is O(n log n).



给定了我们一个数字，让我们求子数组之和大于等于给定值的最小长度

解决方案

有两种解法
1. 二分搜索
如果知道了长度为k，验证是否有长度为k和大于等于s的子数组需要的复杂度是O(n-k)，因为一共有(n-k+1)个长度为k的子数组。
k是[1, n]之间的，用二分搜索去搜索这个区间找到最小的k。所以总复杂度是O(nlgn)
solution1.cpp

2. 双指针
左指针表示起点，右指针搜索终点。假设起点i所能搜索到的终点是j，即[i, j]，那i+1只需要从j开始遍历
总复杂度是O(n)
solution2.cpp





样例


