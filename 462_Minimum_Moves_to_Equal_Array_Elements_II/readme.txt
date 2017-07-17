462_Minimum_Moves_to_Equal_Array_Elements_II


题目大意
Given a non-empty integer array, find the minimum number of moves required to make all array elements equal, where a move is incrementing a selected element by 1 or decrementing a selected element by 1.

You may assume the array's length is at most 10,000.




解决方案
solution.cpp是我自己想出来的，用的时间复杂度是O(nlgn)
本质上还是穷举了所有可能的选项(整个数组变成任一个元素)，然后挑最小的。
先sort数组，...直接看代码吧，这个也不是很有意思，代码里也有注释


solution1.cpp是参考网上的，直接找到中位数，然后所有数字变成中位数就行了。

样例
Example:

Input:
[1,2,3]

Output:
2

Explanation:
Only two moves are needed (remember each move increments or decrements one element):

[1,2,3]  =>  [2,2,3]  =>  [2,2,2]

