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
        if(mmap.find(node) != mmap.end()) return mmap[node];
        UndirectedGraphNode *p = new UndirectedGraphNode(node->label);
        mmap[node] = p;
        for(auto i: node->neighbors)
            p->neighbors.push_back(cloneGraph(i));
        return p;
    }
private:
    unordered_map<UndirectedGraphNode *, UndirectedGraphNode *> mmap;
};