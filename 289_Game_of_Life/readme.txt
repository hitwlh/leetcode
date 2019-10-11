289_Game_of_Life


题目大意
ccording to the Wikipedia's article: "The Game of Life, also known simply as Life, is a cellular automaton devised by the British mathematician John Horton Conway in 1970."

Given a board with m by n cells, each cell has an initial state live (1) or dead (0). Each cell interacts with its eight neighbors (horizontal, vertical, diagonal) using the following four rules (taken from the above Wikipedia article):

Any live cell with fewer than two live neighbors dies, as if caused by under-population.
Any live cell with two or three live neighbors lives on to the next generation.
Any live cell with more than three live neighbors dies, as if by over-population..
Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction.
Write a function to compute the next state (after one update) of the board given its current state.

Follow up: 
Could you solve it in-place? Remember that the board needs to be updated at the same time: You cannot update some cells first and then use their updated values to update other cells.
In this question, we represent the board using a 2D array. In principle, the board is infinite, which would cause problems when the active area encroaches the border of the array. How would you address these problems?


解决方案
生命游戏中，对于任意细胞，规则如下：
每个细胞有两种状态-存活或死亡，每个细胞与以自身为中心的周围八个细胞产生互动。（如图，黑色为存活，白色为死亡）
当前细胞为存活状态时，当周围低于2个（不包含2个）存活细胞时， 该细胞变成死亡状态。（模拟生命数量稀少）
当前细胞为存活状态时，当周围有2个或3个存活细胞时， 该细胞保持原样。
当前细胞为存活状态时，当周围有3个以上的存活细胞时，该细胞变成死亡状态。（模拟生命数量过多）
当前细胞为死亡状态时，当周围有3个存活细胞时，该细胞变成存活状态。 （模拟繁殖）

soluiton1.cpp
新开一个数组vec，在vec保留下一轮，求vec[i][j]只要看board[i][j]周围8个细胞的情况
但是这不满足follow up，因为follow up要求是直接在board里修改。


soluiton2.cpp
用4个状态：
0: died->died, 1: died->live, 2: live->died, 3: live->live
到某个位置时直接修改，但是修改的时候要保留原来的live/died信息，因此用4个状态

注意求周围8个的时候，就有两类了，前面修改过的是0/1/2/3，后面没修改过的是0/1


样例


