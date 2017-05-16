class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int ret = 0;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] == 1){
                    int count = 4;
                    if(isisland(grid, i-1, j)) count--;
                    if(isisland(grid, i+1, j)) count--;
                    if(isisland(grid, i, j-1)) count--;
                    if(isisland(grid, i, j+1)) count--;
                    ret += count;
                }
            }
        }
        return ret;
    }
private:
    bool isisland(vector<vector<int>>& grid, int x, int y){
        if(x >= 0 && x < grid.size() && y >= 0 && y < grid[0].size() && grid[x][y] == 1) return true;
        return false;
    }
};