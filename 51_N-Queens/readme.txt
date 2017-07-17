51_N-Queens


题目大意
The n-queens puzzle is the problem of placing n queens on an n×n chessboard such that no two queens attack each other.


Given an integer n, return all distinct solutions to the n-queens puzzle.

Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space respectively.



解决方案
N皇后问题，就是在NxN的棋盘上摆放N个皇后，使得每个皇后不能吃到另外的(不在同一行、同一列、同一斜线上）

是个回溯问题，其实并不难，但是这里的解决方案是参考了submit的，因为怎么检测某个位置可摆放是蛮有讲究的。
这里摆放的时候是逐行放的，因此新摆放的时候，只需要考虑摆放的这个棋子会不会造成行、列冲突(一共2*N的检测数量)，以及往上检测是否有斜线冲突(下面现在全都还没摆放，不可能有斜线冲突)

具体可看代码，非常好懂。

样例
For example,
There exist two distinct solutions to the 4-queens puzzle:

[
 [".Q..",  // Solution 1
  "...Q",
  "Q...",
  "..Q."],

 ["..Q.",  // Solution 2
  "Q...",
  "...Q",
  ".Q.."]
]

