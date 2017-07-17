233_Number_of_Digit_One


题目大意
Given an integer n, count the total number of digit 1 appearing in all non-negative integers less than or equal to n.

解决方案
先推算所有1位数(1...9)、2位数(10...99)、3位数(100...999)...里头的1，大致是十倍递增，返回类型是int，所以只需要计算到12位数就行了
定义long reg[12], sum[12];
reg[i] 表示i位数里有reg[i]个1
sum[i] = reg[0] + reg[1] + ... + reg[i]
初始reg[1] = 1, sum[1] = 1;
从 2 开始
reg[i] = pow(10, i-1) + 9 * sum[i-1];
sum[i] = sum[i-1] + reg[i];

求好reg和sum数组之后，在求cal(n)时，假设n有x位，最高位是a，则1有下面几个来源：

1. 最高位是0, 1, 2,..., a-1时除最高位外，共有(s[0] - '0') * sum[s.length()-1];个1
2. 如果最高位是1，那么由最高位可获得n - pow(10, s.length()-1) + 1个1，如果不是，则最高位为1的共有pow(10, s.length()-1)个
3. 去掉n的最高位之后递归调用


样例
For example:
Given n = 13,
Return 6, because digit 1 occurred in the following numbers: 1, 10, 11, 12, 13.

