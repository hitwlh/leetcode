204_Count_Primes


题目大意
Count the number of prime numbers less than a non-negative number, n.

解决方案
这题的难度是easy，但是事实上只是编程简单，并不容易想到解法。
解法是开一个size == n的bool数组并初始化，然后从2开始标记倍数
如
(2),4,6,8,10,12...
(3),6,9,12....
(5),10,15,20...
(7),14,21,28,35,42,49...
最后再累加（2,3,5,7...）的个数就ok

样例


