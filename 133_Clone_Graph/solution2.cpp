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
        myque.push(node);
        UndirectedGraphNode *HEAD = new UndirectedGraphNode(node->label);
        mmap[node] = HEAD;
        while(!myque.empty()){
            UndirectedGraphNode* front = myque.front();
            myque.pop();
            for(auto i: front->neighbors){
                if(i){
                    if(mmap.find(i) == mmap.end()){
                        UndirectedGraphNode *p = new UndirectedGraphNode(i->label);
                        mmap[i] = p;
                        myque.push(i);
                    }
                    mmap[front]->neighbors.push_back(mmap[i]);
                }else
                    mmap[front]->neighbors.push_back(NULL);
            }
        }
        return HEAD;
    }
private:
    unordered_map<UndirectedGraphNode *, UndirectedGraphNode *> mmap;
    queue<UndirectedGraphNode *> myque;
};