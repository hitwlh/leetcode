371_Sum_of_Two_Integers


题目大意
Calculate the sum of two integers a and b, but you are not allowed to use the operator + and -.



解决方案
首先要确认这道题没有溢出。

这题首先要理解int类型的加法是怎么做的(关键是负数这里有疑惑)
只考虑正数加法：按位进行加，则00相加得0，01相加得1，11相加得0，说明可以用异或实现，但是11相加得0需要进位，这可以用与来实现
这就搞明白了怎么做加法。
然后是负数：考虑-2+1和-1+(-1)仔细想一想会发现仍然适用

样例

Example:
Given a = 1 and b = 2, return 3.
