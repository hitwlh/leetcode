bool compare(pair<int, int> a, pair<int, int> b){
    if(a.first == b.first) return a.second < b.second;
    return a.first < b.first;
}
class Solution {
public:
    vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people) {
        vector<pair<int, int>> ret;
        if(people.empty()) return ret;
        ret.assign(people.size(), {-1, -1});
        sort(people.begin(), people.end(), compare);
        ret[people[0].second] = people[0];
        int same = 0;
        for(int i = 1; i < people.size();i++){
            int to = people[i].second, now = 0, already = 0;
            if(people[i].first == people[i-1].first) same++;
            else same = 0;
            //for(auto i: ret) cout  << "[" << i.first << " " << i.second << "]"; cout << endl;
            while(true){
                //cout << to << " " << already << " " << now << "]\n";
                if(ret[now].first == -1){
                    if(already == to-same){
                        ret[now] = people[i];
                        break;
                    }
                    already++;
                }
                now++;
            }
        }
        return ret;
    }
};