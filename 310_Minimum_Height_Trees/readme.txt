310_Minimum_Height_Trees


题目大意
For a undirected graph with tree characteristics, we can choose any node as the root. The result graph is then a rooted tree. Among all possible rooted trees, those with minimum height are called minimum height trees (MHTs). Given such a graph, write a function to find all the MHTs and return a list of their root labels.

Format
The graph contains n nodes which are labeled from 0 to n - 1. You will be given the number n and a list of undirected edges (each edge is a pair of labels).

You can assume that no duplicate edges will appear in edges. Since all edges are undirected, [0, 1] is the same as [1, 0] and thus will not appear together in edges.



解决方案
注意这里的树就是无向无环图，因此root其实就是最长路的中点


这题的解法都是网上找到的，关键是这个就是一棵树！！！

第一种策略是，找到最长路，然后找中点(1个或2个)，solution1.cpp
这里需要找最长路，方法是随便从一个点开始走，bfs，走到最远的点s1，然后以这个点为起点bfs，找到最远的点s2。s1到s2的就是最长路径，两次bfs，也就是两个O(n)的开销
知道最长路径的起点、终点之后，需要找这条路的中点
solution1.cpp里的解法是用dfs先求出s1到s2的长度，然后再从s1出发用dfs，找到长度为一半的点。两个O(n)的开销
总的开销是4个O(n)，n是顶点个数



第二种策略是先计算每个点的degree，然后将degree为1的点放入list或者queue中进行计算，把这些点从neighbours中去除，然后计算接下来degree = 1的点。最后剩下的1 - 2个点就是新的root
这个算法的开销就是 树高*O(n)，这个算法比较好写
one-time-attention
最后剩下的是一个节点还是两个节点？如果剩下一个节点，这个节点的degree会变为0
因此
不能每次找degree为1的(可能最后应该找degree为0的)！！！因此访问过的结点的degree不能设为0，而应设为-1



solution3.cpp
可以证明：最长路可能有很多条，但是所有最长路的中点，都是相同的。
因此只需要做4次bfs
第1次bfs：随机挑一个起点，走到最远的点startindex,
第2次bfs：startindex为起点，走到最远的点endindex,记录长度length
第3次bfs：startindex为起点，走(length+1) / 2步，记录中点(注意中点可能是1个，也可能是2个)
第4次bfs：endindex为起点，走(length+1) / 2步，记录中点(注意中点可能是1个，也可能是2个)
求中点集合的交集，即可。 


样例

Example 1:

Given n = 4, edges = [[1, 0], [1, 2], [1, 3]]

        0
        |
        1
       / \
      2   3
return [1]

Example 2:

Given n = 6, edges = [[0, 3], [1, 3], [2, 3], [4, 3], [5, 4]]

     0  1  2
      \ | /
        3
        |
        4
        |
        5
return [3, 4]
