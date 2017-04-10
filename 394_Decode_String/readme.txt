394_Decode_String


题目大意
Given an encoded string, return it's decoded string.

The encoding rule is: k[encoded_string], where the encoded_string inside the square brackets is being repeated exactly k times. Note that k is guaranteed to be a positive integer.

You may assume that the input string is always valid; No extra white spaces, square brackets are well-formed, etc.

Furthermore, you may assume that the original data does not contain any digits and that digits are only for those repeat numbers, k. For example, there won't be input like 3a or 2[4].

解决方案
这题非常难。可以尝试死记一下吧：遇到数字则累加获得数字结果到number，遇到字母则累加获得当前字母到t，遇到[则将number和t分别入栈并且重置当前number和t
遇到]则将t乘以数字栈的栈顶，再加上字母栈的栈顶作为新的t，再弹出数字栈和字母栈


核心是：遇到数字的话，要把当前的串入栈，因为当前的串是不需要乘以当前需要入栈的数字的。数字只和在它后面入栈的进行乘，这是key point
用3[abc15[d]5[ab]]这个稍微检验一下就知道了

样例
s = "3[a]2[bc]", return "aaabcbc".
s = "3[a2[c]]", return "accaccacc".
s = "2[abc]3[cd]ef", return "abcabccdcdcdef".

