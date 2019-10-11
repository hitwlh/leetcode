368_Largest_Divisible_Subset


题目大意
Given a set of distinct positive integers, find the largest subset such that every pair (Si, Sj) of elements in this subset satisfies: Si % Sj = 0 or Sj % Si = 0.

If there are multiple solutions, return any subset is fine.

给一个数组，求这样一个子集合，集合中的任意两个数相互取余均为0



解决方案
对于正确的解(一个集合)，里面的元素显然有大小顺序
在搜索最大的解集合时，最大的元素只需要和前面的解中可模并且size最大的去拼接就行了，这样就能找到每个元素作为最大元素所能获取的最大集合(如果size相等，那么加到最小的序列里去)。全部计算完成之后再从头到尾遍历一遍找到最大集合是多大，就行了。
因此是动态规划。








样例

Example 1:

nums: [1,2,3]

Result: [1,2] (of course, [1,3] will also be ok)
Example 2:

nums: [1,2,4,8]

Result: [1,2,4,8]
