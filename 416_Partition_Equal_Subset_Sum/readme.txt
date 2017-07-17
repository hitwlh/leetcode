416_Partition_Equal_Subset_Sum


题目大意
Given a non-empty array containing only positive integers, find if the array can be partitioned into two subsets such that the sum of elements in both subsets is equal.

Note:
Each of the array element will not exceed 100.
The array size will not exceed 200.



解决方案
这题我是直接看了参考答案。其实这题跟背包问题挺像的。仔细看一下数据范围，大致也就明白了两层for循环应该这样：
for(int i = 0; i < nums.size(); i++)
    for(int j = target; j >= nums[i]; j--)
不容易想到的是target：这题要划分成2个背包，那么不然sum是偶数，然后就是要从这些里头找一些数，令其sum == accumulate(nums.begin(), nums.end(), 0)/2;
这就成了背包问题。也是蛮巧妙的。


样例
Example 1:

Input: [1, 5, 11, 5]

Output: true

Explanation: The array can be partitioned as [1, 5, 5] and [11].
Example 2:

Input: [1, 2, 3, 5]

Output: false

Explanation: The array cannot be partitioned into equal sum subsets.

