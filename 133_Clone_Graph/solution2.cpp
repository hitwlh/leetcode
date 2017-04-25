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
        que.push(node);
        UndirectedGraphNode *HEAD = new UndirectedGraphNode(node->label);
        uumap[node] = HEAD;
        que.push(node);
        bfs();
        return HEAD;
    }
private:
    map<UndirectedGraphNode *, UndirectedGraphNode *> uumap;
    map<UndirectedGraphNode *, bool> visit;
    queue<UndirectedGraphNode *> que;
    void bfs(){
        while(!que.empty()){
            UndirectedGraphNode *top = que.front();
            que.pop();
            if(visit.find(top) == visit.end()){
                visit[top] = true;
                for(int i = 0; i < top->neighbors.size(); i++){
                    if(uumap.find(top->neighbors[i]) == uumap.end()){
                        //visit[top->neighbors[i]] = true;
                        UndirectedGraphNode *use = new UndirectedGraphNode(top->neighbors[i]->label);
                        uumap[top->neighbors[i]] = use;
                        uumap[top]->neighbors.push_back(use);
                        que.push(top->neighbors[i]);
                    }else uumap[top]->neighbors.push_back(uumap[top->neighbors[i]]);
                }
            }
        }
    }
};