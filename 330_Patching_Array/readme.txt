330_Patching_Array


题目大意
Given a sorted positive integer array nums and an integer n, add/patch elements to the array such that any number in range [1, n] inclusive can be formed by the sum of some elements in the array. Return the minimum number of patches required.



解决方案
这题思路不难，代码也简单。就是从左侧往右侧遍历，假如通过nums[0...i]，并且添加数字过后，可以sum的区间是[1, could]，
那下一个需要sum的是could+1， 
如果nums[i+1]<=could+1，那用它nums[i+1] + (could+1-nums[i+1])就得到could+1了，并且could+1-nums[i+1]一定是<=could的， 前面已经能够表示[1, could]了。
如果nums[i+1] > could+1，那就表示不了了只能添加could+1到数组里，并且添加完之后，可以sum的区间就是[1, could+could+1]。

one-time-attention
1. could不能是int变量，因为could有倍增的可能，这个倍增可能超出int类型。


样例
Example 1:
nums = [1, 3], n = 6
Return 1.

Combinations of nums are [1], [3], [1,3], which form possible sums of: 1, 3, 4.
Now if we add/patch 2 to nums, the combinations are: [1], [2], [3], [1,3], [2,3], [1,2,3].
Possible sums are 1, 2, 3, 4, 5, 6, which now covers the range [1, 6].
So we only need 1 patch.

Example 2:
nums = [1, 5, 10], n = 20
Return 2.
The two patches can be [2, 4].

Example 3:
nums = [1, 2, 2], n = 5
Return 0.

