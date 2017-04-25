class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if(grid.empty()) return 0;
        my_grid = grid;
        int ret = 0;
        for(int i = 0; i < my_grid.size(); i++){
            for(int j = 0; j < my_grid[i].size(); j++){
                if(my_grid[i][j] == '1'){
                    my_grid[i][j] = '0';
                    my_queue.push({i, j});
                    ret++;
                    bfs(i, j);
                }
            }
        }
        return ret;
    }
private:
    vector<vector<char>> my_grid;
    queue<pair<int, int>> my_queue;
    void bfs(int i, int j){
        while(!my_queue.empty()){
            my_push(my_queue.front().first-1, my_queue.front().second);
            my_push(my_queue.front().first+1, my_queue.front().second);
            my_push(my_queue.front().first, my_queue.front().second-1);
            my_push(my_queue.front().first, my_queue.front().second+1);
            my_queue.pop();
        }
    }
    void my_push(int i, int j){
        if(i >= 0 && i < my_grid.size() && j >= 0 && j < my_grid[i].size() && my_grid[i][j] == '1')
            my_grid[i][j] = '0', my_queue.push({i,j});
    }
};