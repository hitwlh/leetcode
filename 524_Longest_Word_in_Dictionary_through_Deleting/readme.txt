524_Longest_Word_in_Dictionary_through_Deleting


题目大意
Given a string and a string dictionary, find the longest string in the dictionary that can be formed by deleting some characters of the given string. If there are more than one possible results, return the longest word with the smallest lexicographical order. If there is no possible result, return the empty string.


Note:
All the strings in the input will only contain lower-case letters.
The size of the dictionary won't exceed 1,000.
The length of all the strings in the input won't exceed 1,000.


给了我们一个字符串，和一个字典，让我们找到字典中最长的一个单词，这个单词可以通过给定单词通过删除某些字符得到。

解决方案
看下这题的数据量就知道这题其实挺容易的。用双指针进行比较，看一个串是否是另一个串的子串。
sort一下，这样找到的第一个子串就可以ok了





样例
Example 1:
Input:
s = "abpcplea", d = ["ale","apple","monkey","plea"]

Output: 
"apple"
Example 2:
Input:
s = "abpcplea", d = ["a","b","c"]

Output: 
"a"

