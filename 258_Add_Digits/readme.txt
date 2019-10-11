258_Add_Digits


题目大意
Given a non-negative integer num, repeatedly add all its digits until the result has only one digit.

For example:

Given num = 38, the process is like: 3 + 8 = 11, 1 + 1 = 2. Since 2 has only one digit, return it.

Follow up:
Could you do it without any loop/recursion in O(1) runtime?

解决方案
第一个解决方案就是直接循环获得每位然后相加，然后循环处理直到结果小于10
代码在solution1.cpp
one-time-attention
处理一个数字的时候要看while(num)
一开始写成了while(num % 10)那就变成了看个位数是否是0，错了

第二个解决方案
常量时间
设A = am...a1a0
也就是A = a0 + a1 * 10 + a2 * 10^2  +... + am * 10^m
 = a0 + a1 + a2 + ... + am + a1 * 9 + a2 * 99 + ... + am * (10^m - 1)
且(a1 * 9 + a2 * 99 + ... + am * (10^m - 1)) % 9  == 0
所以A % 9 == (a0 + a1 + a2 + ... + am) % 9
每次累加模9的操作对于原数直接取模9是一样的，但只适用于x≢0(mod9)


1    1
2    2
3    3
4    4
5    5
6    6
7    7
8    8    
9    9    
10    1
11    2
12    3    
13    4
14    5
15    6
16    7
17    8
18    9
19    1
20    2
根据上面的列举，
dr(n) = 
0, n=0
9, n!=0 && n%9 == 0
n % 9, n%9 != 0


结合起来就是1 + ((num - 1) % 9)
solution2.cpp

样例


