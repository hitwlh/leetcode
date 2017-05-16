491_Increasing_Subsequences


题目大意

Note:
The length of the given array will not exceed 15.
The range of integer in the given array is [-100,100].
The given array may contain duplicates, and two equal integers should also be considered as a special case of increasing sequence.
Note:
The length of the given array will not exceed 15.
The range of integer in the given array is [-100,100].
The given array may contain duplicates, and two equal integers should also be considered as a special case of increasing sequence.



解决方案
就是要找出所有递增序列。这个问题可以等价于到了某个位置选与不选，如果这个位置的元素比前面大，可以选
抽象成这样就和494很像了。
这题蛮典型的，值得记忆。




样例
Example:
Input: [4, 6, 7, 7]
Output: [[4, 6], [4, 7], [4, 6, 7], [4, 6, 7, 7], [6, 7], [6, 7, 7], [7,7], [4,7,7]]

