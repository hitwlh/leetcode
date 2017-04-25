529_Minesweeper


题目大意
Let's play the minesweeper game (Wikipedia, online game)!

You are given a 2D char matrix representing the game board. 'M' represents an unrevealed mine, 'E' represents an unrevealed empty square, 'B' represents a revealed blank square that has no adjacent (above, below, left, right, and all 4 diagonals) mines, digit ('1' to '8') represents how many mines are adjacent to this revealed square, and finally 'X' represents a revealed mine.

Now given the next click position (row and column indices) among all the unrevealed squares ('M' or 'E'), return the board after revealing this position according to the following rules:

If a mine ('M') is revealed, then the game is over - change it to 'X'.
If an empty square ('E') with no adjacent mines is revealed, then change it to revealed blank ('B') and all of its adjacent unrevealed squares should be revealed recursively.
If an empty square ('E') with at least one adjacent mine is revealed, then change it to a digit ('1' to '8') representing the number of adjacent mines.




题意：扫雷，给出要单击的位置。然后返回点了那个位置的结果

解决方案
如果点到雷，标记为X，然后直接返回
如果点到的不是雷。
如果那个点周边全都不是雷，把这个点设置为空，然后递归点周边
否则把这个位置标记为周边雷的个数，然后返回。

one-time-attention
这里要注意点了一个位置之后修改的时候要修改成char类型，别直接修改成int型的1、2、3、4...
因为click是引用类型的，所以不能直接传{1, 1}，而要定义一个vec变量等于{1, 1}，然后传递这个变量



样例


