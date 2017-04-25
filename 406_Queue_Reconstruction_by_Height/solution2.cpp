bool compare(pair<int, int> a, pair<int, int> b){
    if(a.first == b.first) return a.second < b.second;
    return a.first > b.first;
}
class Solution {
public:
    vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people) {
        vector<pair<int, int>> ret;
        if(people.empty()) return ret;
        sort(people.begin(), people.end(), compare);
        ret.insert(ret.begin(), people[0]);
        for(int i = 1; i < people.size(); i++){
            int second = people[i].second;
            ret.insert(ret.begin()+second, people[i]);
        }
        return ret;
    }
};