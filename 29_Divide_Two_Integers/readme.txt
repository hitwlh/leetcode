29_Divide_Two_Integers


题目大意
Divide two integers without using multiplication, division and mod operator.
If it is overflow, return MAX_INT.



解决方案
基本的思路，举例10/3来说，
10/3 = 6/3 + 3/3 + 1/3。商的二进制是11，按照这种算法得到的也就是11，就是分母一直去减分子的若干2次幂倍
需要注意的点：
1.转化为long long去做移位运算，比如(0x4000~0x7fff)/1，1都需要左移到最高位才能约过被除数的最高位，但是左移到最高位在int里表示的是负数，这就出错了，所有必须用long long，这是运算时的越界溢出
2.还有另一种是结果的越界溢出，仔细想一想，int除法只有INT_MIN/(-1)会发生越界溢出，所以在程序开头用if判断一下就ok了


样例


