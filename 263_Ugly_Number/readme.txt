263_Ugly_Number


题目大意
Write a program to check whether a given number is an ugly number.
Ugly numbers are positive numbers whose prime factors only include 2, 3, 5. For example, 6, 8 are ugly while 14 is not ugly since it includes another prime factor 7.
Note that 1 is typically treated as an ugly number.

解决方案
就是反复看能不能整除2、3、5就是了，如果不行并且不是剩1就返回false，如果整除到最后是1，就返回true

样例


