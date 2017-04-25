557_Reverse_Words_in_a_String_III


题目大意
Given a string, you need to reverse the order of characters in each word within a sentence while still preserving whitespace and initial word order.

解决方案
非常简单，就是找到空格，然后把空格和上次空格之间的给reverse
有个要点就是，起始的起点是0，这个容易想到。
ont-time-attention
但是最后一个单词的结束不是空格，而是到头，因此跳出循环后还要把最后一个单词再reverse一次

样例


