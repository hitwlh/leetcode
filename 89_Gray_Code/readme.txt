89_Gray_Code


题目大意
The gray code is a binary numeral system where two successive values differ in only one bit.

Given a non-negative integer n representing the total number of bits in the code, print the sequence of gray code. A gray code sequence must begin with 0.

解决方案


n位元的格雷码可以从n-1位元的格雷码以上下镜射后加上新位元的方式快速的得到。这种方法基于格雷码是反射码的事实，利用递归的如下规则来构造：

1位格雷码有两个码字
(n+1)位格雷码中的前2^n个码字等于n位格雷码的码字，按顺序书写，加前缀0
(n+1)位格雷码中的后2^n个码字等于n位格雷码的码字，按逆序书写，加前缀1

具体参见
https://zh.wikipedia.org/wiki/%E6%A0%BC%E9%9B%B7%E7%A0%81
镜射排列





样例
For example, given n = 2, return [0,1,3,2]. Its gray code sequence is:

00 - 0
01 - 1
11 - 3
10 - 2

