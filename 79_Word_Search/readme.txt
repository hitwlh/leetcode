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


