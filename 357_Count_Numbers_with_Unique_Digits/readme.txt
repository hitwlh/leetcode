357_Count_Numbers_with_Unique_Digits


题目大意
Given a non-negative integer n, count all numbers with unique digits, x, where 0 ≤ x < 10n.
找一个范围内的各位上不相同的数字，比如123就是各位不相同的数字，而11,121,222就不是这样的数字。




解决方案
题意：满足题意的数字是各位均不相同，如121就不满足，个位和百位相同。

1. 直接构造+动态规划
位数为n时，最高位可以是1~9任选(9种可能)，次高位因为可以用0了，所以还是9种可能，往后每低一位选择少1.
因此f(k) = 9 * 9 * 8 * ... (9 - k + 2) (k>=2)
f(2) = 9 * 9
再按照动规，两位数的所有解答，后面可以再增加的是8种可能。也就是
f(3) = 9 * 9 * 8 = f(2) * 8
f(4) = 9 * 9 * 8 * 7= f(2) * 7
所以可以直接O(10)得到答案。具体看solution.cpp


2. 回溯
其实就是另类的"遍历"
最高位从1~9遍历，其余位从0~9遍历，并且用的不能是出现过的。

核心就是
used[i] = true;
...
used[i] = false;
代码solution1.cpp
效率非常低下！


样例
Example:
Given n = 2, return 91. (The answer should be the total numbers in the range of 0 ≤ x < 100, excluding [11,22,33,44,55,66,77,88,99])

