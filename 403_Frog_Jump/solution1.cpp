class Solution {
public:
    bool canCross(vector<int>& stones) {
        unordered_map<int, int> mymap;
        unordered_map<int, bool> tmp;
        for(int i = 0; i < stones.size(); i++) mymap[stones[i]] = i;
        vector<unordered_map<int, bool>> step(stones.size(), tmp);
        if(stones[1] != 1) return false;
        step[1][1] = true, step[1][2] = true;
        int now = 1;
        while(now < stones.size()){
            for(auto i: step[now]){
                if(i.first - 1 > 0)
                    step[mymap[stones[now] + i.first]][i.first-1] = true;
                step[mymap[stones[now] + i.first]][i.first+1] = true;
                step[mymap[stones[now] + i.first]][i.first] = true;
            }
            now++;
        }
        return !step.back().empty();
    }
};