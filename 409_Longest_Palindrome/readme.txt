409_Longest_Palindrome


题目大意
Given a string which consists of lowercase or uppercase letters, find the length of the longest palindromes that can be built with those letters.
This is case sensitive, for example "Aa" is not considered a palindrome here.
Note:
Assume the length of given string will not exceed 1,010.



解决方案
给一堆字符，求用这些字符能组成的最长回文串。
就是看每个字符有多少偶数个(添加到开头结尾)，然后看下添加完是否还有字符，如果有，就往中间再填一个字符。




样例
Example:

Input:
"abccccdd"
Output:
7
Explanation:
One longest palindrome that can be built is "dccaccd", whose length is 7.

