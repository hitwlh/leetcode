414_Third_Maximum_Number


题目大意
Given a non-empty array of integers, return the third maximum number in this array. If it does not exist, return the maximum number. The time complexity must be in O(n).

让我们求数组中第三大的数，如果不存在的话那么就返回最大的数，题目中说明了这里的第三大不能和第二大相同，必须是严格的小于，而并非小于等于。

解决方案

就是遍历三次，但是有一个要注意的就是可能有数组里有INT_MIN，因此不能用if(max3 != INT_MIN) 判断max3是否存在，对于这点有2种解决方法：
1. max3可能等于INT_MIN,因此定义bool max3_e = false;表示是否存在max3
one-time-attention
在判断的时候要用 if(max1 <= nums[i])，因为可能第三小的就是和INT_MIN相等，如果只是小于，就漏掉了

样例
Example 1:
Input: [3, 2, 1]

Output: 1

Explanation: The third maximum is 1.
Example 2:
Input: [1, 2]

Output: 2

Explanation: The third maximum does not exist, so the maximum (2) is returned instead.
Example 3:
Input: [2, 2, 3, 1]

Output: 1

Explanation: Note that the third maximum here means the third maximum distinct number.
Both numbers with value 2 are both considered as second maximum.

