448_Find_All_Numbers_Disappeared_in_an_Array


题目大意
Given an array of integers where 1 ≤ a[i] ≤ n (n = size of array), some elements appear twice and others appear once.
Find all the elements of [1, n] inclusive that do not appear in this array.
Could you do it without extra space and in O(n) runtime? You may assume the returned list does not count as extra space.

解决方案
1. 我想到的解决方案是，从头遍历，把改写的数字写到正确的地方，比如：
[4,3,2,7,8,2,3,1]
[4,3,2,4,8,2,3,1]， 保留7
[4,3,2,4,8,2,7,1]， 保留3
[4,3,3,4,8,2,7,1]， 保留2
[4,2,3,4,8,2,7,1]
[4,2,3,4,8,2,7,8]， 保留1
[1,2,3,4,8,2,7,8]
最后遍历一遍，得到[5, 6]
这种解法要保留，所以需要2个变量
solution1.cpp

2. 另一个解决方案是参考网上的
遍历nums数组，将其中已经存在的数对应的下标序列取出，将nums[下标序列] 的数标记为负。之后再遍历一遍nums数组，只要是非负的数，就把此下标取出，存入结果数组result。最后返回result。
solution2.cpp


第二种解法符合题意，不用extra space， 并且第二种解法非常好写

样例
Example:

Input:
[4,3,2,7,8,2,3,1]

Output:
[5,6]

