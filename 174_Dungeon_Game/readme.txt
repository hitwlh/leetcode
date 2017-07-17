174_Dungeon_Game


题目大意
The demons had captured the princess (P) and imprisoned her in the bottom-right corner of a dungeon. The dungeon consists of M x N rooms laid out in a 2D grid. Our valiant knight (K) was initially positioned in the top-left room and must fight his way through the dungeon to rescue the princess.

The knight has an initial health point represented by a positive integer. If at any point his health point drops to 0 or below, he dies immediately.

Some of the rooms are guarded by demons, so the knight loses health (negative integers) upon entering these rooms; other rooms are either empty (0's) or contain magic orbs that increase the knight's health (positive integers).

In order to reach the princess as quickly as possible, the knight decides to move only rightward or downward in each step.

Write a function to determine the knight's minimum initial health so that he is able to rescue the princess.

Notes:

The knight's health has no upper bound.
Any room can contain threats or power-ups, even the first room the knight enters and the bottom-right room where the princess is imprisoned.








解决方案
这题还蛮有意思的，我一开始想错了。
我一开始的做法是从起点开始走，就能用动规算出走到[i][j]至多还能剩余多少生命值(允许负数)
但是这样不知道沿路所需要的最大生命值，而从终点往回反向搜索也是不可行的。在图形内部，某个点可由其左部和上部到达，而某个位置其实有2个属性用来衡量，一个是到达该位置所需要的最小初始生命值(+)，另一个是到达该位置时沿路获得的生命值(+/-)。因此在选择上一步是左还是上时，并不知道改选哪个。
因此WA了好几次。
看反例：
1 -2 3
2 -2 -2

到某个点是沿路所得到生命值：
1 -1 2 
3 1 0
在计算record[1][2]时用的是right->right->down路径

计算出这个有什么用？
从record[1][2]往回搜索。照样不知道上一步是record[1][1]还是record[0][2]。


正确的思路是从终点往回思考：
既然已经知道终点的开销了(正/负)，也就是知道进入终点前至少应该有多少生命值了。
除了终点，其余所有点，肯定都是要往右或者往下走的。最后一列的点只能往下走，因此可以得到最后一列点，在进入它们之前最少要有多少生命值(才能最后到终点)；同理可得到最后一行点进入前所需要的生命值。
然后从右下([m-2][n-2]到左上[0][0])处理其余的点，处理某个点时，已经知道了这个点进入后继点(它的右以及下)之前需要多少生命值，挑一个更小的，就是离开这个点所需要的最小生命值，再看这个点本身有多少开销，就知道了进入这个点之前至少要有多少生命值。这样一直计算到[0][0]，原问题就得到了解。
one-time-attention
1. 在进入最后一个点[m-1][n-1]前，即使[m-1][n-1]处的开销是收益，也至少要有1的生命值。反映在代码上就是：
record[m-1][n-1] = (dungeon[m-1][n-1] >= 0) ? 1 : (1 - dungeon[m-1][n-1]);
但是其它点就不需要1 - dungeon[m-1][n-1]，只需要
if(dungeon[m-1][i] >= record[m-1][i+1]) record[m-1][i] = 1;
else record[m-1][i] = record[m-1][i+1] - dungeon[m-1][i];
也就是else后面接的不是record[m-1][i] = record[m-1][i+1] - dungeon[m-1][i] + 1;
因为后继结点进入之前就是1，那进入本节点之前是“0”就行，事实上并不是0，因为最后一个结点的要求就是满足1了。比如下一个结点的要求是8，这个点的开销是+5，那进入这个点之前有3就行了，因为3保证了活命(能进本节点)，+5之后就得到了8，如果用record[m-1][i] = record[m-1][i+1] - dungeon[m-1][i] + 1;得到4，那就多余了。








样例

For example, given the dungeon below, the initial health of the knight must be at least 7 if he follows the optimal path RIGHT-> RIGHT -> DOWN -> DOWN.

-2(K)   -3      3
-5      -10     1
10      30      -5(P)
