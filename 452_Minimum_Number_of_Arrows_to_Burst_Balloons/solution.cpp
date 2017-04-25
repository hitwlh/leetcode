bool compare(pair<int, int> a, pair<int, int> b){
    if(a.first == b.first) return a.second < b.second;
    return a.first < b.first;
}
class Solution {
public:
    int findMinArrowShots(vector<pair<int, int>>& points) {
        sort(points.begin(), points.end(), compare);
        int i = 0, ret = 0;
        int min_end = -1;
        while(i < points.size()){
            min_end = points[i].second;
            while(i+1 < points.size() && points[i+1].first <= min_end){
                i++;
                min_end = min(min_end, points[i].second);
            }
            ret++;
            i++;
        }
        return ret;
    }
};