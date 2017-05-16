367_Valid_Perfect_Square


题目大意

Given a positive integer num, write a function which returns True if num is a perfect square else False.
Note: Do not use any built-in library function such as sqrt.

解决方案
就是挺简单的二分搜索。但是要注意不能直接用mid * mid 去和num比较，因为mid * mid会超出int范围
在solution.cpp里用的是除法和求模结合起来判断。

另外一种方法就是转成long long 了，但是要注意也不能long long mul = mid * mid;因为右侧是int类型的乘法，自然也溢出了
这种方法比较耗时，就没copy过来了



样例
Example 1:
Input: 16
Returns: True

Example 2:
Input: 14
Returns: False