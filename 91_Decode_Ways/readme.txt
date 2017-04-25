91_Decode_Ways


题目大意
A message containing letters from A-Z is being encoded to numbers using the following mapping:

'A' -> 1
'B' -> 2
...
'Z' -> 26
Given an encoded message containing digits, determine the total number of ways to decode it.

解决方案
动态规划，要注意的一点是0的处理，如果输入的是"0"，应该返回0

样例
For example,
Given encoded message "12", it could be decoded as "AB" (1 2) or "L" (12).

The number of ways decoding "12" is 2.

Subscribe to see which companies asked this question.

Show Tags


