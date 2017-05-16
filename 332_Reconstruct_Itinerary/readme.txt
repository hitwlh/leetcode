332_Reconstruct_Itinerary


题目大意
Given a list of airline tickets represented by pairs of departure and arrival airports [from, to], reconstruct the itinerary in order. All of the tickets belong to a man who departs from JFK. Thus, the itinerary must begin with JFK.

Note:
If there are multiple valid itineraries, you should return the itinerary that has the smallest lexical order when read as a single string. For example, the itinerary ["JFK", "LGA"] has a smaller lexical order than ["JFK", "LGB"].
All airports are represented by three capital letters (IATA code).
You may assume all tickets form at least one valid itinerary.




解决方案
处理到一个点a时有如下三种可能：
a->b->c->d...
a->b->...->a->c->...
a->c->...->a->b...
第一种是没有环，一条直线往下走就是了
第二种是有环，并且是字典序自然碰到环
第三种是有环，但是环不是字典序，按照字典序进入b了


第一种很好说，直接就完事了。
第二种其实和第一种一样，当成没有环就ok
第三种有点麻烦，因为按照字典序会先处理b。这里用栈来处理，当栈顶的顶点没有路径时，就把栈顶写到路径的头部。当栈顶的顶点有路径时，就把路径压栈。


solution2.cpp是我自己想出来的解法，这个解法比较粗糙。也是dfs，但是这种解法在把一条边加入结果时，不知道这样做是否有解，所以只能遍历整张图去看是否有解，如果没解，就要回溯到下一个状态再做。由于每条边处理的时候都要看是否能遍历整张图，因此复杂度是O(E^2)


样例
Example 1:
tickets = [["MUC", "LHR"], ["JFK", "MUC"], ["SFO", "SJC"], ["LHR", "SFO"]]
Return ["JFK", "MUC", "LHR", "SFO", "SJC"].
Example 2:
tickets = [["JFK","SFO"],["JFK","ATL"],["SFO","ATL"],["ATL","JFK"],["ATL","SFO"]]
Return ["JFK","ATL","JFK","SFO","ATL","SFO"].
Another possible reconstruction is ["JFK","SFO","ATL","JFK","ATL","SFO"]. But it is larger in lexical order.



