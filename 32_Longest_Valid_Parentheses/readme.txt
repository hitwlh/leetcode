32_Longest_Valid_Parentheses


题目大意
Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.

解决方案
1.动态规划
https://discuss.leetcode.com/topic/2426/my-dp-o-n-solution-without-using-stack/4
If s[i] is '(', set longest[i] to 0,because any string end with '(' cannot be a valid one.

Else if s[i] is ')'

     If s[i-1] is '(', longest[i] = longest[i-2] + 2

     Else if s[i-1] is ')' and s[i-longest[i-1]-1] == '(', longest[i] = longest[i-1] + 2 + longest[i-longest[i-1]-2]
代码在solution1.cpp里

2.
用栈来保存当前起点，并用一个指向当前匹配最左侧的指针
遇到(，把当前索引入栈
遇到)，如果栈为空，说明匹配失败，直接索引往后走一个
如果栈不空，先弹栈，
如果这时栈空，说明完成了全部左括号的匹配，那当前匹配长度就是当前索引减去左指针，再把左指针置为下一个位置
如果这时栈不空，那么当前匹配的长度就是当前索引减去栈顶+1，因为当前栈顶后一个位置就是当前匹配的起点！！
代码在solution2.cpp里


样例
For "(()", the longest valid parentheses substring is "()", which has length = 2.
Another example is ")()())", where the longest valid parentheses substring is "()()", which has length = 4.

