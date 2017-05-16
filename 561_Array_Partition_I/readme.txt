561_Array_Partition_I


题目大意
Given an array of 2n integers, your task is to group these integers into n pairs of integer, say (a1, b1), (a2, b2), ..., (an, bn) which makes sum of min(ai, bi) for all i from 1 to n as large as possible.
Note:
n is a positive integer, which is in the range of [1, 10000].
All the integers in the array will be in the range of [-10000, 10000].



解决方案
把2n个数字分配从n个pair，也就有n个min(ai, bi)，要让他们的和最大。
显然最大的数用不上，为了用到次大，只能用它和最大组合...这里应该有一个贪心选择性。
知道这个之后就容易了，先sort，然后跳跃着选nums[0] nums[2] nums[4]...

样例
Example 1:
Input: [1,4,3,2]

Output: 4
Explanation: n is 2, and the maximum sum of pairs is 4.

