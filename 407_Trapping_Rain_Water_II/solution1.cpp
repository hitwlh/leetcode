class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        if(heightMap.empty() || heightMap[0].empty()) return 0;
        m = heightMap.size(), n = heightMap[0].size(), ret = 0;
        visited.assign(m, vector<bool>(n, false));
        for(int i = 0; i < m; i++){
            q.push({heightMap[i][0], i, 0});
            q.push({heightMap[i][n-1], i, n-1});
            visited[i][0] = true;
            visited[i][n-1] = true;
        }
        for(int i = 1; i + 1 < n; i++){
            q.push({heightMap[0][i], 0, i});
            q.push({heightMap[m-1][i], m-1, i});
            visited[0][i] = true;
            visited[m-1][i] = true;
        }
        bfs(heightMap);
        return ret;
    }
private:
    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> q;
    int m, n, ret = 0, pheight = INT_MIN;
    vector<vector<int>> direction = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
    vector<vector<bool>> visited;
    bool isvalid(int i, int j){
        return i >= 0 and j >= 0 and i < m and j < n;
    }
    void bfs(vector<vector<int>>& heightMap){
        while(!q.empty()){
            int x = q.top()[1], y = q.top()[2];
            pheight = max(q.top()[0], pheight);
            q.pop();
            for(int i = 0; i < 4; i++){
                int xx = x + direction[i][0], yy = y + direction[i][1];
                if(isvalid(xx, yy) && !visited[xx][yy]){
                    visited[xx][yy] = true;
                    q.push({heightMap[xx][yy], xx, yy});
                    if(heightMap[xx][yy] < pheight)
                        ret += pheight - heightMap[xx][yy];
                }
            }
        }
    }
};