class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
        if(n == 1) return {0};
        if(n == 2) return {0,1};
        nodesedge.assign(n, {});
        for(auto i: edges) nodesedge[i.first].push_back(i.second), nodesedge[i.second].push_back(i.first);
        int MIN = INT_MAX, last1 = -1, last2 = -1;
        queue<int> que;
        que.push(0);
        while(!que.empty()){
            int front = que.front();
            last1 = front;
            proced[front] = true;
            que.pop();
            for(int i = 0; i < nodesedge[front].size(); i++){
                if(proced.find(nodesedge[front][i]) == proced.end())
                    que.push(nodesedge[front][i]);
            }
        }
        que.push(last1);
        proced.clear();
        while(!que.empty()){
            int front = que.front();
            last2 = front;
            proced[front] = true;
            que.pop();
            for(int i = 0; i < nodesedge[front].size(); i++){
                if(proced.find(nodesedge[front][i]) == proced.end())
                    que.push(nodesedge[front][i]);
            }
        }
        level = 0;
        proced.clear();
        dfs(last1, last2);
        length = level;
        level = 0;
        proced.clear();
        find_middle(last1, last2);
        return ret;
    }
private:
    int level, length;
    vector<int> ret;
    vector<vector<int>> nodesedge;
    unordered_map<int, bool> proced;
    bool find_middle(int now, int tosearch){
        proced[now] = true;
        if(now == tosearch){
            level++;
            return true;
        }
        for(auto i: nodesedge[now]){
            if(proced.find(i) == proced.end() && find_middle(i, tosearch)){
                level++;
                if((length % 2) && (level == (length+1) / 2))
                    ret.push_back(now);
                else if(!(length % 2) && (level == length / 2 || level == length / 2 + 1))
                    ret.push_back(now);
                return true;
            }
        }
        return false;
    }
    bool dfs(int now, int tosearch){
        proced[now] = true;
        if(now == tosearch){
            level++;
            return true;
        }
        for(auto i: nodesedge[now]){
            if(proced.find(i) == proced.end() && dfs(i, tosearch)){
                level++;
                return true;
            }
        }
        return false;
    }
};