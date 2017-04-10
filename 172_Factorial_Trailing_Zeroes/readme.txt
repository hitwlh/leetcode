172_Factorial_Trailing_Zeroes


题目大意
Given an integer n, return the number of trailing zeroes in n!.

解决方案
这题的核心是n!这一串数字能整除5多少次。
数字分为若干类：
第一类：5、10、15、20、30，只能整除5一次
第二类：25
第三类：125
...
n/5就是第一类的数目
(n/5)/5就是第二类的数目
...

样例


