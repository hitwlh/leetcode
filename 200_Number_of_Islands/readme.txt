200_Number_of_Islands


题目大意
Given a 2d grid map of '1's (land) and '0's (water), count the number of islands. An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

求矩阵中连续区域的个数

解决方案
这就是个简单的搜索题，找到起点，然后搜索所有邻接点并将其改为‘0’
注意这题深搜和广搜都可以，貌似深搜比较好些而且能快点

注意：如果是广搜写法，要在将点push之前就将当前点的‘1’改为‘0’，这样才能保证一个点只入队一次。
例子：
...1 1...
...1...
...
如果先push{0,0}，再将[0][0]改为0，那它会push{0,1}{1,0}，而在查找{0,1}的时候，它会看到{1,0}还是1，这样{1,0}就会再次被入队，这个效果会导致超时或者超内存

样例

Example 1:

11110
11010
11000
00000
Answer: 1

Example 2:

11000
11000
00100
00011
Answer: 3
