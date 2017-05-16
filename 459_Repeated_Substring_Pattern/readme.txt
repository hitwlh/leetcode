459_Repeated_Substring_Pattern


题目大意
Given a non-empty string check if it can be constructed by taking a substring of it and appending multiple copies of the substring together. You may assume the given string consists of lowercase English letters only and its length will not exceed 10000.



解决方案
直接从1到s.length()-1遍历子串长度，然后判断子串是否能构成原串



样例
Example 1:
Input: "abab"
Output: True

Explanation: It's the substring "ab" twice.
Example 2:
Input: "aba"

Output: False
Example 3:
Input: "abcabcabcabc"
Output: True

Explanation: It's the substring "abc" four times. (And the substring "abcabc" twice.)

