class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int m = dungeon.size(), n = dungeon[0].size();
        vector<vector<int>> record(m, vector<int>(n, 0));//record[i][j]表示为了进入[i][j]，在进入前的生命值是多少，生命值至少是1
        record[m-1][n-1] = (dungeon[m-1][n-1] >= 0 ) ? 1 : (1 - dungeon[m-1][n-1]);
        for(int i = m-2; i >= 0; i--){
            if(dungeon[i][n-1] >= record[i+1][n-1]) record[i][n-1] = 1;
            else record[i][n-1] = record[i+1][n-1] - dungeon[i][n-1];
        }
        for(int i = n-2; i >= 0; i--){
            if(dungeon[m-1][i] >= record[m-1][i+1]) record[m-1][i] = 1;
            else record[m-1][i] = record[m-1][i+1] - dungeon[m-1][i];
        }
        for(int i = m-2; i >= 0; i--){
            for(int j = n-2; j >= 0; j--){
                int need = min(record[i+1][j], record[i][j+1]);
                if(dungeon[i][j] >= need) record[i][j] = 1;
                else record[i][j] = need - dungeon[i][j];
            }
        }
        return record[0][0];
    }
};