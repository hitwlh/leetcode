125_Valid_Palindrome


题目大意
Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

解决方案
判断回文，并且忽略所有非数字、字母
这题其实很trick，如果我想先处理string让每个字符都合法，然后判断是否是回文，很麻烦，因为处理string挺麻烦的
所有可以直接来个双向指针

样例

For example,
"A man, a plan, a canal: Panama" is a palindrome.
"race a car" is not a palindrome.
