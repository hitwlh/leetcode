336_Palindrome_Pairs


题目大意
Given a list of unique words, find all pairs of distinct indices (i, j) in the given list, so that the concatenation of the two words, i.e. words[i] + words[j] is a palindrome.

解决方案
这道题直接暴力会超时。假设所有字符串的长度都是k，有n个字符串。
那么暴力解法就是把所有可能的组合拼接起来，再看是否回文。开销是O(n^2 * k)

这里的解法是O(n * k ^ 2)的
首先以所有字符串的逆序作为key建立一个map，在words里的下标作为映射值。
然后顺序处理，对一个字符串，划分成left right两部分，left从空一直到s.substr(0, s.length()-1)，相应地right从s.substr(0)一直到s.substr(s.length()-1)。然后，如果left是回文的，那看看right是否能在map里找到，反之，如果right是回文的，看看left是否能在map里找到
处理每个串的开销是O(k^2)，有n个串，因此总开销是O(n * k ^ 2)


样例
Example 1:
Given words = ["bat", "tab", "cat"]
Return [[0, 1], [1, 0]]
The palindromes are ["battab", "tabbat"]
Example 2:
Given words = ["abcd", "dcba", "lls", "s", "sssll"]
Return [[0, 1], [1, 0], [3, 2], [2, 4]]
The palindromes are ["dcbaabcd", "abcddcba", "slls", "llssssll"]

