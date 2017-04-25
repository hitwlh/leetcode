133_Clone_Graph


题目大意

Clone an undirected graph. Each node in the graph contains a label and a list of its neighbors.


OJ's undirected graph serialization:
Nodes are labeled uniquely.

We use # as a separator for each node, and , as a separator for node label and each neighbor of the node.
As an example, consider the serialized graph {0,1,2#1,2#2,2}.

The graph has a total of three nodes, and therefore contains three parts as separated by #.

First node is labeled as 0. Connect node 0 to both nodes 1 and 2.
Second node is labeled as 1. Connect node 1 to node 2.
Third node is labeled as 2. Connect node 2 to node 2 (itself), thus forming a self-cycle.
Visually, the graph looks like the following:

       1
      / \
     /   \
    0 --- 2
         / \
         \_/





解决方案
就是想要拷贝整张图。这个的难点在于拷贝一个点的时候，不知道它的儿子结点指针(因为儿子结点也是要拷贝完才知道的)


solution1.cpp是dfs解法
dfs代码比较简洁，逻辑也比较清晰。
如果一个node访问过，就直接返回node在新图里的指针
如果没访问过，就新建结点，label相同，标记为访问过，然后新结点push(旧结点的所有子节点递归调用dfs)



solution2.cpp是bfs解法
bfs的解法就更难明白儿子指针了
核心在于要有两个map
一个map是map<UndirectedGraphNode *, bool> visit;，判断一个node是否处理过
另一个map是map<UndirectedGraphNode *, UndirectedGraphNode *> uumap;从老图的结点映射到新图的结点




样例


