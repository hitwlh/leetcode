523_Continuous_Subarray_Sum


题目大意
Given a list of non-negative numbers and a target integer k, write a function to check if the array has a continuous subarray of size at least 2 that sums up to the multiple of k, that is, sums up to n*k where n is also an integer.

Note:
The length of the array won't exceed 10,000.
You may assume the sum of all the numbers is in the range of a signed 32-bit integer.
这道题给了我们一个数组和一个数字k，让我们求是否存在这样的一个连续的子数组，该子数组的数组之和可以整除k


解决方案
第一种方案非常好想，就是暴力穷举，枚举起点和长度，然后用一个sum数组，这种解法在solution.cpp
one-time-attention
要特别注意k是0怎么办，如果不处理这个情况，模k的时候会有除0错误。但是也不是k=0就直接返回false/true,而是需要找是否有和为0的子数组，这个也需要注意。

第二种方案
当处理到A[j]时，如果sum[j] % k = l, 前面如果出现过sum[i] % k = l， 那说明sum[i+1, ..., j]能%k，因此只需要保存前面出现过的余数就行了。

因为题目要求至少有2个数字，所以需要满足 i < j-1；
还有就是要能判断sum[0, 1, ..., j]，如果不做特殊处理，起点只能是i+1开始，也就是起点只从1开始，这错了。解决这点有两种方式：
1. 增加13行的if(t == 0 && i > 0) return true;
2. 28行的mymap[0] = -1;
solution1.cpp里保存了两种代码，就是因为解决这个有不同的方式，而且不需要sum数组，只用sum int变量就行了。






样例

Example 1:
Input: [23, 2, 4, 6, 7],  k=6
Output: True
Explanation: Because [2, 4] is a continuous subarray of size 2 and sums up to 6.

Example 2:
Input: [23, 2, 6, 4, 7],  k=6
Output: True
Explanation: Because [23, 2, 6, 4, 7] is an continuous subarray of size 5 and sums up to 42.

