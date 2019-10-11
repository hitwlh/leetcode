22_Generate_Parentheses


题目大意
Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

这道题给定一个数字n，让生成共有n个括号的所有正确的形式

解决方案
()()()
   ())  
 (()))
  ))()
   ())

这样的序列满足以下要求：
从任意位置往左看，'('都不比')'少，并且只要满足这个要求就ok
因此我自己画，当前有要么画'('要么画')'，画完再递归调用，既然当前画的已经不同，那么递归调用最后画出的整体看肯定就不同
因此就ok了

   
样例

For example, given n = 3, a solution set is:

[
  "((()))",
  "(()())",
  "(())()",
  "()(())",
  "()()()"
]
