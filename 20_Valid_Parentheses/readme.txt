20_Valid_Parentheses


题目大意
Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.



解决方案
直接用一个栈，遇到右括号弹栈并匹配，遇到左括号压栈

样例


