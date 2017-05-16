461_Hamming_Distance


题目大意
Total Accepted: 55311
Total Submissions: 78271
Difficulty: Easy
Contributors:
Samuri
The Hamming distance between two integers is the number of positions at which the corresponding bits are different.
Given two integers x and y, calculate the Hamming distance.
Note:
0 ≤ x, y < 231.

解决方案
直接异或一下，然后看看里头有多少个1


样例
Example:
Input: x = 1, y = 4
Output: 2
Explanation:
1   (0 0 0 1)
4   (0 1 0 0)
       ↑   ↑
The above arrows point to positions where the corresponding bits are different.

