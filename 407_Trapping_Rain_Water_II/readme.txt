407_Trapping_Rain_Water_II


题目大意
Given an m x n matrix of positive integers representing the height of each unit cell in a 2D elevation map, compute the volume of water it is able to trap after raining.

Note:
Both m and n are less than 110. The height of each unit cell is greater than 0 and is less than 20,000.

解决方案
题意翻译：给出二维表，表示一系列柱子的高度，然后下雨，求下完雨这个二维表里能留下多少雨水
我一开始的思路：
用广搜的方法，先从四周往里，求出不能积水的柱子，将四周的柱子加入队列，然后看旁边，如果旁边高度高于或等于，则继续入队，这样就能求出所有不能积水的柱子。换句话说，这次bfs完还没visit过的柱子就是能积水的柱子，但是积水的柱子具体积水多少呢？我的做法是，对所有visit为1的柱子，用广搜的做法找到这一个块的边界的最小值，
比如这样的图：
14 17 18 16 14 16 
17 3  10 2  3  8 
11 10 4  7  1  7 
13 7  2  9  8  10 
13 1  3  4  8  6 
20 3  3  9  10 8 
从边界开始广搜的结果是:
0 0 0 0 0 0 
0 1 1 1 1 0 
0 1 1 1 1 0 
0 1 1 0 0 0 
0 1 0 0 0 0 
0 0 0 0 0 0 
这里所有为1的区域，构成了一个块，这个块的边界的最小高度是heightMap[5][1]，也就是3
我原先的理解是这个区域的水不能超过3这样就只有两个高为1，两个高为2的柱子能盛水，才盛6。
但是错了！！！以heightMap[1][3]、heightMap[1][4]、heightMap[2][4]为例，这几个不是到3就不能再涨了，其实应该7
也就是说一个块内，也可能有一些“凹槽”，这个块内的凹槽能盛的水量不取决于整个块的边界，而取决于这个凹槽所属的小块的边界。比如一块平地，中间有四个柱子夹着一个柱子，这四个柱子的高度是无穷大，那它夹的高度也就是无穷大了

所以我的整个想法都直接破产！！！




参考了网上的解题思路
http://www.cnblogs.com/grandyang/p/5928987.html
用优先队列的方式，每次选高度最小的柱子。
初始将四周入队，然后广搜，
需要保留一个变量，这个变量的更新方式是tmp_height = max(first, tmp_height);也就是它表示当前的水面是多高
如果队首元素的四周有严格低于它的，那那个更低的柱子能存水的量tmp_height - my_heightMap[x][y];然后入队那个更低的柱子。

切记tmp_height保存的是最大值，就是说它只增不减。
其实这种做法就相当于增涨水面，依次求得哪些柱子应该积水tmp_height高度


这题还是需要经常看一看，因为这个思路直观上可以想到，但是数学证明貌似挺难的，我没想得很清楚。


solution1.cpp里保存的是bfs，这个参考了网上的写法

solution2.cpp里保存的是dfs，这是我为了加深理解而写的。dfs时要先把四周都判断完(写进优先队列里)，然后再dfs(如果四周的前进路线不止一条，选择高度最低的那个去前进)。假如一遇到一个更小的就写进优先队列然后就去dfs的话，是错误的。
其实不从数学角度想来写dfs，光看程序等价性，很容易发现dfs和bfs的程序是等价的，而且代码就加了一行而已。。。







样例
Given the following 3x6 height map:
[
  [1,4,3,1,3,2],
  [3,2,1,3,2,4],
  [2,3,3,2,3,1]
]

Return 4.
https://leetcode.com/problems/trapping-rain-water-ii/#/description
原题里有这个样例的图片

