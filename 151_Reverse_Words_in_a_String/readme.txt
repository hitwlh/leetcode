151_Reverse_Words_in_a_String


题目大意
Given an input string, reverse the string word by word.


解决方案
直接翻转整个string，再翻转每个word。
注意如果stirng里左侧、右侧有空格，或者有连续的空格，都要删掉。因此要对string进行预处理

易错点
1. 判断单词结尾，除了遇到空格，还可能是到了string的末尾，如果是到了string的末尾，还需要再加一，因为我后面处理的时候右侧是开区间，左侧是闭区间


样例
For example,
Given s = "the sky is blue",
return "blue is sky the".

