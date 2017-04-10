229_Majority_Element_II


题目大意
Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times. The algorithm should run in linear time and in O(1) space.

解决方案
如果Majority Element元素存在，那将三个不同的数字删除之后, 在剩余的数组中Majority Element仍然是Majority Element
但需要注意这是一个必要条件，即：
将三个不同的数字删除之后, 在剩余的数组中Majority Element不一定是原数组的Majority Element，因此要将剩余的数组中的Majority Element拿回原数组中进行验证

样例


