303_Range_Sum_Query_-_Immutable


题目大意
Given an integer array nums, find the sum of the elements between indices i and j (i ≤ j), inclusive.

Note:
You may assume that the array does not change.
There are many calls to sumRange function.



解决方案
用一个vector保存从起点到当前点的累加和，这样nums[i...j] == my_nums[j] - my_nums[i-1];
有2点需要注意，输入的vector如果是空，应该直接返回，而不是去累加
累加的时候如果i==0，要小心别访问到了my_nums[-1];



样例
Example:
Given nums = [-2, 0, 3, -5, 2, -1]
sumRange(0, 2) -> 1
sumRange(2, 5) -> -1
sumRange(0, 5) -> -3

