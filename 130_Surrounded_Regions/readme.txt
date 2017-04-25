130_Surrounded_Regions


题目大意
Given a 2D board containing 'X' and 'O' (the letter O), capture all regions surrounded by 'X'.

A region is captured by flipping all 'O's into 'X's in that surrounded region.

解决方案
这题容易想到用广搜。但是广搜的起点很不容易，因为如果如果用内部的点做广搜起点，那找到了内部的块，还要判断那些块是否到了边缘来判断是否要将其设置为X，因此换一个思路，把四周作为起点，然后进行广搜，如果广搜到了O点，将其设置为‘1’，这样就把应该保留的O都标记好了，然后将整张表中剩下的O都修改为‘X’，然后把1修改成O，就行了

one_time_attention!!! 
for(int i = 0; i < board[0].size(); i++)
            my_queue.push({0, i}), my_queue.push({board.size()-1, i});
用了这个，但是事实上board[0]可能不存在，这样就错了！！！因此上来要先判断board是否为空！！！

还有个没想到的要点：就是每次都检查上下左右，那可能(0,1)->(1,1)->(0,1)->(1,1)...反复入队。幸好我把入队的O点设置为‘1’了，就保证了不会第二次入队。

这题的queue的定义方法是queue<pair<int,int>> my_queue;

样例
For example,
X X X X
X O O X
X X O X
X O X X
After running your function, the board should be:

X X X X
X X X X
X X X X
X O X X

