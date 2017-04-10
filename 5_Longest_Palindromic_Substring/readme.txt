5_Longest_Palindromic_Substring


题目大意
Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.

解决方案
参考http://www.cnblogs.com/bitzhuwei/p/Longest-Palindromic-Substring-Par-I.html
有若干种解法，动态规划是O(N^2)
我理解的做法是：
选择回文串的中点，一共有O(2N-1)个可能的中点，从中点往左右看最长的子串，代价O(N)
因此这种做法的总复杂度是O(N^2)

样例
Example:

Input: "babad"

Output: "bab"

Note: "aba" is also a valid answer.
Example:

Input: "cbbd"

Output: "bb"

