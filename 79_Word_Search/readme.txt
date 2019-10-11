79_Word_Search


题目大意
Given a 2D board and a word, find if the word exists in the grid.
The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once.

解决方案
深搜
one-time-attention
二维数组初始化
memset(flag[i], true, n*sizeof(bool));
不能写成 memset(flag+i, true, n*sizeof(bool));

trips
因为每次失败后都会将修改过的bool array还原，所以在主函数里只需要初始化bool一次，不需要每次调用前都将bool array全设置一次

solution2.cpp
第二次写得比较简洁。

理解，这里对dfs和回溯产生了疑问，这两个是同样的吗？
讨论帖： http://www.1point3acres.com/bbs/thread-137584-1-1.html


样例
For example,
Given board =

[
  ['A','B','C','E'],
  ['S','F','C','S'],
  ['A','D','E','E']
]
word = "ABCCED", -> returns true,
word = "SEE", -> returns true,
word = "ABCB", -> returns false.


