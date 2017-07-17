316_Remove_Duplicate_Letters


题目大意
Given a string which contains only lowercase letters, remove duplicate letters so that every letter appear once and only once. You must make sure your result is the smallest in lexicographical order among all possible results.


解决方案

题目翻译：一个包含重复字符的字符串，把重复字符都删掉，并且得到的字符串要满足字典序最大

思路参考http://zhuixin8.com/2016/10/02/leetcode-316/
其实这题好像本身以及数学上看，都不是hard。
加入从左到右扫描，扫描到一个字符，如果这个字符不在答案里，就把它加到答案里，那加到答案的什么位置呢？
如果答案靠右侧字符比当前字符大：若后面还有这样的字符，就可以删掉(到后面再加进来)，如果后面没有，那就不能删。
one-time-attention
1. 第16行，如果字符被删掉了，那要把它置为false
2. 第11行，处理到这个字符的时候，要把它的出现次数-1





样例
Example:
Given "bcabc"
Return "abc"

Given "cbacdcbc"
Return "acdb"

