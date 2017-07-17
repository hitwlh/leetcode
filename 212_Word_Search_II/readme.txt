212_Word_Search_II


题目大意
Given a 2D board and a list of words from the dictionary, find all words in the board.

Each word must be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once in a word.


Note:
You may assume that all inputs are consist of lowercase letters a-z.



解决方案
这题和79题非常像，只不过是变成了多个单词需要查询。

solution1.cpp
直接套用79题的代码，查询到有某个单词的话，把它push_back到结果里就是了

solution2.cpp
先对所有单词建立字典树，然后在做dfs的时候，
1. 如果dfs时超出了字典树，直接返回
2. dfs没超出字典
a. 如果当前单词恰好是一个要search的单词，那把它push_back到结果里，并在字典里将这个单词删除掉。
b. 否则递归深搜四个方向
这里要注意的是如果单词列表有相同单词(比如有两个"a"，但是答案里不能有两个"a")，必须做删除操作，因此补充了删除的函数。 字典树参考了208题的字典树，但是208题里没有实现del。删除函数还是挺不好写的，稍微参考了一点http://www.tuicool.com/articles/MvYnMrj
主要还是自己写，就是如果一个位置要删除，能找到那个位置，而那个位置没有儿子，就可以把它删了，并且在父亲的数组里把这个位置修改为空。



易错点
1. 就是给的words里可能有重复的，如果不做处理，答案里也有重复的，就错了。



样例
For example,
Given words = ["oath","pea","eat","rain"] and board =

[
  ['o','a','a','n'],
  ['e','t','a','e'],
  ['i','h','k','r'],
  ['i','f','l','v']
]
Return ["eat","oath"].

