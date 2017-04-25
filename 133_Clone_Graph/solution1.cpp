/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if(!node) return NULL;
        return dfs(node);
    }
private:
    map<UndirectedGraphNode *, UndirectedGraphNode *> visit;
    UndirectedGraphNode *dfs(UndirectedGraphNode *now){
        if(visit.find(now) == visit.end()){
            UndirectedGraphNode *copy = new UndirectedGraphNode(now->label);
            visit[now] = copy;
            for(int i = 0; i < now->neighbors.size(); i++)
                copy->neighbors.push_back(dfs(now->neighbors[i]));
        }
        return visit[now];
    }
};