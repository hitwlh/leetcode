279_Perfect_Squares


题目大意
Given a positive integer n, find the least number of perfect square numbers (for example, 1, 4, 9, 16, ...) which sum to n.
For example, given n = 12, return 3 because 12 = 4 + 4 + 4; given n = 13, return 2 because 13 = 4 + 9.

解决方案
这题的tag是广搜、数论、动规。
但是广搜的解法没想到，网上也没见到刚搜ac的代码，也懒得找了，这题直观看明显是dp。

dp解法
需要从n往前遍历一遍找到最合适的，为什么要遍历？一开始我想的是尽量每次减多一点
反例：
12 = 9 + 1 + 1 + 1
12 = 4 + 4 + 4
说明不能简单地每次减最少
那就动规喽，直接从1遍历到sqrt(n)去找
for(int i = q; i >= 1; i--){
            int numSquaresq = 1 + ret[n-i*i];
            if(numSquaresq < MIN && numSquaresq != -1 )
                MIN = numSquaresq;
        }
ret[n]表示n最少能被几个整数平方和，求ret[n]之前，先把它前面的所有ret都求出来
动规的代码在solution1.cpp

数论解法
参考http://www.jianshu.com/p/2925f4d7511b
用到四平方和定理：
一个正整数数一定能表示为4个数的平方和。因此答案是[1,4]
如果这个数是4^k(8m+7)。那就一定是4个整数平方和，直接返回4就ok了
否则答案是[1,3]
从1遍历到n，看看是否是1或者2，如果都不是，最后直接返回3
代码在solution2.cpp
注意a要从0开始，以输入5为例，如果不从0开始，那就会用上3^2 + 4^2 = 25，这就返回2，错了




样例


