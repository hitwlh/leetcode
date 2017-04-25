207_Course_Schedule


题目大意
There are a total of n courses you have to take, labeled from 0 to n - 1.
Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]
Given the total number of courses and a list of prerequisite pairs, is it possible for you to finish all courses?


Note:
The input prerequisites is a graph represented by a list of edges, not adjacency matrices. Read more about how a graph is represented.
You may assume that there are no duplicate edges in the input prerequisites.



解决方案
这题就是拓扑排序然后看有没有环
L ← Empty list that will contain the sorted elements
S ← Set of all nodes with no incoming edges
while S is non-empty do
    remove a node n from S
    add n to tail of L
    for each node m with an edge e from n to m do
        remove edge e from the graph
        if m has no other incoming edges then
            insert m into S
if graph has edges then
    return error (graph has at least one cycle)
else 
    return L (a topologically sorted order)


上面是拓扑排序的算法，就是找到所有没有前序的顶点，然后将其设置为起点
注意一个tip，就是如何判断一个点有没有前序
可以用一个数组存储一个点的前序的个数，然后每次找到无前序点时，就把它的所有后序点的前序个数减1，如果减完得到0就说明那个点没有前序点了，可以入队。这样算法的时间复杂度是O(V+E)




样例

For example:

2, [[1,0]]
There are a total of 2 courses to take. To take course 1 you should have finished course 0. So it is possible.

2, [[1,0],[0,1]]
There are a total of 2 courses to take. To take course 1 you should have finished course 0, and to take course 0 you should also have finished course 1. So it is impossible.


