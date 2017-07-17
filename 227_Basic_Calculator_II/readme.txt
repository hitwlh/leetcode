227_Basic_Calculator_II


题目大意
Implement a basic calculator to evaluate a simple expression string.

The expression string contains only non-negative integers, +, -, *, / operators and empty spaces . The integer division should truncate toward zero.

You may assume that the given expression is always valid.

解决方案
没有括号、小数点等。
我一开始的解法用了栈，发现那个真是太难写了，各种出错。
参考了solution，里面的解法有一大值得借鉴的地方就是如何处理s，读数据，用了流，非常精彩。
istringstream in('+' + s + '+');
解决的方法是，对乘法、除法，直接对num1一直运算，当读到加减法时，就可以把num1并入结果里。
非常精彩。

样例
Some examples:
"3+2*2" = 7
" 3/2 " = 1
" 3+5 / 2 " = 5

