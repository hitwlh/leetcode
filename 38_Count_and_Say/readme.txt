38_Count_and_Say


题目大意
The count-and-say sequence is the sequence of integers beginning as follows:
1, 11, 21, 1211, 111221, ...

1 is read off as "one 1" or 11.
11 is read off as "two 1s" or 21.
21 is read off as "one 2, then one 1" or 1211.

Given an integer n, generate the nth sequence.

解决方案
常规解决方案，由n==1开始往上生成，对于某一个字符串，顺序遍历，边遍历边生成

样例


