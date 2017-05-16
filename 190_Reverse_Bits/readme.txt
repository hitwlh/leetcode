190_Reverse_Bits


题目大意
Reverse bits of a given 32 bits unsigned integer.
For example, given input 43261596 (represented in binary as 00000010100101000001111010011100), return 964176192 (represented in binary as 00111001011110000010100101000000).
Follow up:
If this function is called many times, how would you optimize it?
题意为给定无符号32位整数，求该整数翻转(对应的二进制数的翻转)后所得的整数值。



解决方案
每当低位&1的结果为1，说明低位为1，此时将待输出的目标整数(默认值为0)左移动一位并加上1；每当低位&1的结果为0，说明低位为0，此时将待输出的目标整数左移一位即可；循环直到移动完32次，所得目标整数即为所求。

样例


