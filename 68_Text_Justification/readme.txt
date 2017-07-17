68_Text_Justification


题目大意
Given an array of words and a length L, format the text such that each line has exactly L characters and is fully (left and right) justified.

You should pack your words in a greedy approach; that is, pack as many words as you can in each line. Pad extra spaces ' ' when necessary so that each line has exactly L characters.

Extra spaces between words should be distributed as evenly as possible. If the number of spaces on a line do not divide evenly between words, the empty slots on the left will be assigned more spaces than the slots on the right.

For the last line of text, it should be left justified and no extra space is inserted between words.



解决方案
这题是要做文本对齐。输入一些单词，按照给定的行宽度来排列文本(每行字符数都要严格等于maxWidth)

对于非最后一行，左右没有空格，单词之间插入空格，并且保证单词间的空格数相等(如果无法均分，令左侧的单词间比右侧的多一个空格)
对于最后一行，所有单词右边加一个空格，最后再在最后填满空格
填充时要贪心，每行尽量多排列单词(除非排不下)

其实这样说完之后这题怎么解基本也就清楚了。难点在于细节，这里很多细节，我也错了两三次。。
还有个易错点是
words[0].empty()时
返回的vector里的是string(maxWidth, ' ')
而不是""


样例

words: ["This", "is", "an", "example", "of", "text", "justification."]
L: 16.

Return the formatted lines as:
[
   "This    is    an",
   "example  of text",
   "justification.  "
]
