453_Minimum_Moves_to_Equal_Array_Elements


题目大意
Given a non-empty integer array of size n, find the minimum number of moves required to make all array elements equal, where a move is incrementing n - 1 elements by 1.

解决方案
题目翻译：一个数组，每次可以选择任意n-1个数进行+1，需要多少次才能让数组全部数字相等？
任意n-1个数进行+1等价于最大数-1
因此只需要计算数组里每个数字与最小数字的差，求和，就ok






样例


Example:

Input:
[1,2,3]

Output:
3

Explanation:
Only three moves are needed (remember each move increments two elements):

[1,2,3]  =>  [2,3,3]  =>  [3,4,3]  =>  [4,4,4]