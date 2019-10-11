238_Product_of_Array_Except_Self


题目大意
Given an array of n integers where n > 1, nums, return an array output such that output[i] is equal to the product of all the elements of nums except nums[i].
Solve it without division and in O(n).

Follow up:
Could you solve it with constant space complexity? (Note: The output array does not count as extra space for the purpose of space complexity analysis.)

给定我们一个数组，让我们返回一个新数组，对于每一个位置上的数是其他位置上数的乘积，并且限定了时间复杂度O(n)，并且不让我们用除法

解决方案
要计算所有连乘，但output[i]里存储的是连乘时没乘自己的结果。
这里的解决方案其实不难想到。
第一种方法是，开辟两个数组A[i] B[i],
A[i]里记录的是nums[0] * ... * nums[i-1]
B[i]里记录的是nums[i+1] * ... * nums[n-1]
这样ret[i] = A[i] * B[i] 就行了
但是这样就多用了空间。其实想一想，只需要把每个位置要乘的内容分成左边一半和右边一半，直接左边连乘一遍、右边连乘一遍就行了。这样就做到了常量空间线性时间。代码里记录的是常量空间的解法。

样例
For example, given [1,2,3,4], return [24,12,8,6].

