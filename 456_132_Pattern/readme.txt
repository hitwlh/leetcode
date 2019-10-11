456_132_Pattern


题目大意
Given a sequence of n integers a1, a2, ..., an, a 132 pattern is a subsequence ai, aj, ak such that i < j < k and ai < ak < aj. Design an algorithm that takes a list of n numbers as input and checks whether there is a 132 pattern in the list.

Note: n will be less than 15,000.

给我们了一个数组，让我们找到132的模式，就是第一个数小于第二第三个数，且第三个数小于第二个数。


解决方案
solution1
先从左到右遍历一遍，记录下a[0]...a[i-1]中的最小值，保存在left[i]里。
然后从右到左找"3"，左侧的"1"越小越好，因此用left[i]，右侧应该是比"1"大里最小的(尽量做到<"3")，因此用一个set保存右边的数字，每次用upper_bound找比"1"大里最小的，如果找到的数<"3"，就返回true

时间复杂度O(nlgn)

solution2
可以先理解一下496. Next Greater Element I
solution2的解法非常像

从右到左扫描，维持一个从上往下递增的栈。以及s2变量表示"2"是多大
处理一个数nums[i]的方法：
1. 如果nums[i]<s2，那就找到"1"了，返回true
2. 如果栈顶的数字<nums[i]，那就把栈顶元素赋值给s2，弹栈。直到栈空或者栈顶>=nums[i]

正确性说明：
如果一个数字入栈，说明这个数字比之前的s2大或相等(否则就返回true了)，因此找到的s2只会递增，并且处理一个数字的时候，如果栈顶比它小，那所有备选的s2都在栈里排着。
时间复杂度O(n)





样例
Example 1:
Input: [1, 2, 3, 4]

Output: False

Explanation: There is no 132 pattern in the sequence.
Example 2:
Input: [3, 1, 4, 2]

Output: True

Explanation: There is a 132 pattern in the sequence: [1, 4, 2].
Example 3:
Input: [-1, 3, 2, 0]

Output: True

Explanation: There are three 132 patterns in the sequence: [-1, 3, 2], [-1, 3, 0] and [-1, 2, 0].

