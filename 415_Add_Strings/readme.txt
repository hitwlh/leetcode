415_Add_Strings


题目大意
Given two non-negative integers num1 and num2 represented as string, return the sum of num1 and num2.

Note:
The length of both num1 and num2 is < 5100.
Both num1 and num2 contains only digits 0-9.
Both num1 and num2 does not contain any leading zero.
You must not use any built-in BigInteger library or convert the inputs to integer directly.



解决方案
这题难度是easy，但是要一次ac反倒很不容易
首先就是它希望我自己实现加法，不要转化成int 或long long之后直接相加，再转成string，因为int、 long long都溢出了
自己实现加法，这里首先要注意的就是位对齐，我写的时候遇到下面几个错：
1. swap(num1, num2);后忘记swap(size1, size2);
2. 某一位加完之后carry忘记置为0
3. 做修改时忘记了'0'

样例


