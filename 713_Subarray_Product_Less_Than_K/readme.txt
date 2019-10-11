713_Subarray_Product_Less_Than_K


题目大意
Your are given an array of positive integers nums.

Count and print the number of (contiguous) subarrays where the product of all the elements in the subarray is less than k.


Note:

0 < nums.length <= 50000.
0 < nums[i] < 1000.
0 <= k < 10^6.



找出乘积小于k的子数组的个数


解决方案
用双指针维护乘积小于k的窗口，每次根据窗口大小，来累加子数组即可。

样例
Example 1:
Input: nums = [10, 5, 2, 6], k = 100
Output: 8
Explanation: The 8 subarrays that have product less than 100 are: [10], [5], [2], [6], [10, 5], [5, 2], [2, 6], [5, 2, 6].
Note that [10, 5, 2] is not included as the product of 100 is not strictly less than k.

