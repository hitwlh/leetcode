class Solution {
public:
    int numberOfBoomerangs(vector<pair<int, int>>& points) {
        map<int, int> mymap;
        int ret = 0;
        for(int i = 0; i < points.size(); i++){
            mymap.clear();
            for(int j = 0; j < points.size(); j++)
                mymap[(points[i].first - points[j].first) * (points[i].first - points[j].first) + (points[i].second - points[j].second) * (points[i].second - points[j].second)]++;
            for(auto i: mymap) ret = ret + i.second * (i.second-1);
        }
        return ret;
    }
};