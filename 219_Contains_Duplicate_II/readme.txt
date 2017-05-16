219_Contains_Duplicate_II


题目大意
Given an array of integers and an integer k, find out whether there are two distinct indices i and j in the array such that nums[i] = nums[j] and the absolute difference between i and j is at most k.


解决方案
用一个map，从左到右遍历数组，处理一个数时，如果这个数未处理过，就在map里更新它的索引，如果处理过，看下是否与前面的索引相差小于k，如果是，就返回true，如果不是，就用新的索引更新k。全部处理完如果不返回true那就是要返回false

样例


