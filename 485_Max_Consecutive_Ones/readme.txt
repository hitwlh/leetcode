485_Max_Consecutive_Ones


题目大意
Given a binary array, find the maximum number of consecutive 1s in this array.
Note:

The input array will only contain 0 and 1.
The length of input array is a positive integer and will not exceed 10,000

解决方案
就是从头到尾遍历一遍就是了，统计1的串长

样例

Example 1:
Input: [1,1,0,1,1,1]
Output: 3
Explanation: The first two digits or the last three digits are consecutive 1s.
The maximum number of consecutive 1s is 3.

