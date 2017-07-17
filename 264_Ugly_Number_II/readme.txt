264_Ugly_Number_II


题目大意
Write a program to find the n-th ugly number.
Ugly numbers are positive numbers whose prime factors only include 2, 3, 5. For example, 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 is the sequence of the first 10 ugly numbers.
Note that 1 is typically treated as an ugly number, and n does not exceed 1690.



解决方案
题目翻译：找第n个丑数。是263题的进阶版本。
参考http://bookshadow.com/weblog/2015/08/19/leetcode-ugly-number-ii/
我一开始的思路大错特错了。我一开始在想求
A[0]: 0个[2, 3, 5]连乘得到的丑数个数
A[1]: 1个[2, 3, 5]连乘得到的丑数个数
A[2]: 2个[2, 3, 5]连乘得到的丑数个数
...
然后求第n个数就是把前面的减掉，然后顺序找A[i]里面的某一个丑数。
错误：
1. A[0] A[1] A[2]...里的丑数不是顺序排列的，比如2x2x2x2 < 5x5
2. 事实上这压根没有“顺序找A[i]里面的某一个丑数”的解法。事实上实现这点就是解出这题了。



正确思路：
每个数字都可以做乘2、乘3、乘5的操作，来得到比它更大的丑数。
因此初始化第一个数字为1，然后用3个指针，每个指针指向的数字是下一次要乘2、乘3、乘5的，要获得新的丑数时，就选3个指针指向的数字乘2、乘3、乘5里头最小的，这就是当前序列的下一个丑数。然后把最小的那个数字的指针右移一位。
这样子就保证了每个丑数都会乘2、乘3、乘5，不会有遗漏。
但是右移的时候不一定只移动一个指针
比如

如果指针指向的3x3x5需要x5
如果指针指向的3x5x5需要x3
那这就重合了，因此两个指针都要挪动。



样例


