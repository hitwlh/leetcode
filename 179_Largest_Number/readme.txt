179_Largest_Number


题目大意
Given a list of non negative integers, arrange them such that they form the largest number.
For example, given [3, 30, 34, 5, 9], the largest formed number is 9534330.
Note: The result may be very large, so you need to return a string instead of an integer.

给了我们一个数组，让我们将其拼接成最大的数

解决方案
转化成string数组然后拿去sort，然后再拼接起来就是了。
难点：如何处理一个字符串是另一个字符串的前缀的情况。
很简单的办法就是拼接起来再比较：p = s1 + s2, q = s2 + s1;
solution2.cpp
比较难的在solution1.cpp，里面不做拷贝，而是直接按照逻辑去进行比较。

one-time-attention
1. 返回前记得对前部的0进行去除
2. 别用for循环去去除

样例


