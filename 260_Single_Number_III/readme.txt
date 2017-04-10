260_Single_Number_III


题目大意
Given an array of numbers nums, in which exactly two elements appear only once and all the other elements appear exactly twice. Find the two elements that appear only once.

解决方案
这题的思路和Single Number挺像
首先知道做Single Number(一个出现1次，其余均出现2次)
如果有2个出现1次， 那对整个数组异或运算的结果就是这两个的异或结果
这个异或结果为1的位，就是这两个数字不相等的位，根据这个位将原数组划分为2份，就将这两个数字分开了，然后对两份分别做Single Number


样例

For example:
Given nums = [1, 2, 1, 3, 2, 5], return [3, 5].
