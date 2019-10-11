139_Word_Break


题目大意
Given a non-empty string s and a dictionary wordDict containing a list of non-empty words, determine if s can be segmented into a space-separated sequence of one or more dictionary words. You may assume the dictionary does not contain duplicate words.

解决方案
经典的动规，从后往前看是否能找到一个单词。单词表里的词可以用无数次
solution1.cpp是从后往前
solution2.cpp更直接、简单，是从前往后


样例
For example, given
s = "leetcode",
dict = ["leet", "code"].



Return true because "leetcode" can be segmented as "leet code".



