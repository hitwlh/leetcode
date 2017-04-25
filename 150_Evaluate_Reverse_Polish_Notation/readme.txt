150_Evaluate_Reverse_Polish_Notation


题目大意
Evaluate the value of an arithmetic expression in Reverse Polish Notation.

Valid operators are +, -, *, /. Each operand may be an integer or another expression.

解决方案
非常简单，用一个栈存储数字就是了
注意-和/的时候除数、被除数要考虑清楚

样例
Some examples:
  ["2", "1", "+", "3", "*"] -> ((2 + 1) * 3) -> 9
  ["4", "13", "5", "/", "+"] -> (4 + (13 / 5)) -> 6

