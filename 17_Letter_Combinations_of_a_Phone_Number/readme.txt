17_Letter_Combinations_of_a_Phone_Number


题目大意
Given a digit string, return all possible letter combinations that the number could represent.
A mapping of digit to letters (just like on the telephone buttons) is given below.

我们求电话号码的字母组合，即数字2到9中每个数字可以代表若干个字母，然后给一串数字，求出所有可能的组合

解决方案
大水题，毫无价值，直接用vector就是了，注意下如果只输入一个数字的情况就行

样例

Input:Digit string "23"
Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
