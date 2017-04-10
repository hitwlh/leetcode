169_Majority_Element


题目大意
Given an array of size n, find the majority element. The majority element is the element that appears more than ⌊ n/2 ⌋ times.
You may assume that the array is non-empty and the majority element always exist in the array.

解决方案
从头到尾遍历，统计到目前为止出现次数大于50%的，如果不大于，则将新的作为备选result

样例


