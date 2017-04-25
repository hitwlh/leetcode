class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        my_heightMap = heightMap;
        if(my_heightMap.empty() || my_heightMap[0].empty()) return 0;
        row = my_heightMap.size(), column = my_heightMap[0].size();
        vector<int> use;
        use.assign(column, 1);
        visit.assign(row, use);
        for(int i = 0; i < column; i++){
            q.push({my_heightMap[0][i], 0* column+i});
            q.push({my_heightMap[row-1][i], (row-1)* column+i});
            visit[0][i] = 0;
            visit[row-1][i] = 0;
        }
        for(int i = 1; i < row-1; i++){
            q.push({my_heightMap[i][0], i* column});
            q.push({my_heightMap[i][column-1], i * column+column-1});
            visit[i][0] = 0;
            visit[i][column-1] = 0;
        }
        dfs();
        return ret;
    }
private:
    void dfs(){
        while(!q.empty()){
            int first = q.top().first, second = q.top().second;
            int r = second / column, c = second % column;
            tmp_height = max(first, tmp_height);
            q.pop();
            for(int i = 0; i < 4; i++){
                int x = r + direct[i][0], y = c + direct[i][1];
                if(is_valid(x, y) && visit[x][y] == 1){
                    q.push({my_heightMap[x][y], x * column + y});
                    visit[x][y] = 0;
                    if(tmp_height > my_heightMap[x][y]){
                        ret += tmp_height - my_heightMap[x][y];
                    }
                }
            }
            dfs();
        }
    }
    vector<vector<int>> my_heightMap;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    int row, column, ret = 0, tmp_height = 0;
    int direct[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    vector<vector<int>> visit, result;
    bool is_valid(int i, int j){
        return i >= 0 && j >= 0 && i < row && j < column;
    }
};