class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
        if(n == 1) return {0};
        if(n == 2) return {0,1};
        degree.assign(n, 0);
        nodesedge.assign(n, {});
        for(auto i: edges){
            nodesedge[i.first].push_back(i.second);
            nodesedge[i.second].push_back(i.first);
            degree[i.first]++;
            degree[i.second]++;
        }
        int last1 = -1, last2 = -1, times = 0, deleted = 0, target = 1;
        while(true){
            times = 0;
            for(int i = 0; i < n; i++){
                if(degree[i] == target){
                    if(times == 0)
                        last1 = i;   
                    else if(times == 1)
                        last2 = i;
                    times++;
                    degree[i] = -1;
                    deleted++;
                    for(int j = 0; j < nodesedge[i].size(); j++)
                        if(degree[nodesedge[i][j]] > 0){
                            del.push(nodesedge[i][j]);
                        }
                }
            }
            while(!del.empty()){
                degree[del.front()]--;
                del.pop();
            }
            if(deleted == n-1) target = 0;
            if(times == 0) break;
        }
        if(target) return {last1, last2};
        return {last1};
    }
private:
    vector<int> ret, degree;
    vector<vector<int>> nodesedge;
    queue<int> del;
};