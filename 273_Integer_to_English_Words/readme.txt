273_Integer_to_English_Words


题目大意
Convert a non-negative integer to its english words representation. 不超过整型范围

解决方案
其实不难，就分割成3位数去读，然后每3位分割加上Thousand、Million、Billion即可

one-time-attention
1. 一些基本的英文错误，"Forty" "Fourteen" ，以及所有单词都是大写字母开头
2. 最要紧的是Hundred、Thousand、Million、Billion后面要不要加空格。直接加肯定不行，因为可能后面没内容，这就多加了；正确的解法是在从高位向低位读数之前判断下是否空，如果不空那就在左侧加上" "作为高位与低位的间隔

样例
For example,
123 -> "One Hundred Twenty Three"
12345 -> "Twelve Thousand Three Hundred Forty Five"
1234567 -> "One Million Two Hundred Thirty Four Thousand Five Hundred Sixty Seven"

