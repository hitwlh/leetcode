385_Mini_Parser


题目大意
Given a nested list of integers represented as a string, implement a parser to deserialize it.

Each element is either an integer, or a list -- whose elements may also be integers or other lists.

Note: You may assume that the string is well-formed:

String is non-empty.
String does not contain white spaces.
String contains only digits 0-9, [, - ,, ].

实现一个迷你解析器用来把一个字符串解析成NestInteger类



解决方案
翻译：看样例就知道题意了。
这个思路不难。就是写代码容易有bug
首先要“找元素”，solution是从右往左找，因此
如果是']'，那往左找到匹配它的'['，这个子串是一个元素(只要字符串合法，左侧一定有'[')
如果是','，那往左找到','，如果左侧没有','，那就是s[0] == '[', s[1...now-1]是一个数字，把它入栈就处理完了。
然后处理栈。对栈里的每个元素递归调用函数，就ok了。

如果从左到右“找元素”，那就把栈换成队列就是了。


one-time-attention
stack要定义成局部的，不能是全局的。否则会不知道什么时候是一个元素。反例：
[[[]], 10, []],如果用全局栈，可能处理成[[], 10, []]





样例
Example 1:

Given s = "324",

You should return a NestedInteger object which contains a single integer 324.
Example 2:

Given s = "[123,[456,[789]]]",

Return a NestedInteger object containing a nested list with 2 elements:

1. An integer containing value 123.
2. A nested list containing two elements:
    i.  An integer containing value 456.
    ii. A nested list with one element:
         a. An integer containing value 789.

