541_Reverse_String_II


题目大意
Given a string and an integer k, you need to reverse the first k characters for every 2k characters counting from the start of the string. If there are less than k characters left, reverse all of them. If there are less than 2k but greater than or equal to k characters, then reverse the first k characters and left the other as original.
Restrictions:
The string consists of lower English letters only.
Length of the given string and k will in the range [1, 10000]

解决方案
用上algorithm的reverse函数，从头到尾，先reverse k长度的子串，然后递增到下一个起始位置。

样例
Example:
Input: s = "abcdefg", k = 2
Output: "bacdfeg"

