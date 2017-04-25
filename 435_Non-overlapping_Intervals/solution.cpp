/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
bool compare(Interval a, Interval b){
    if(a.start == b.start) return a.end < b.end;
    return a.start < b.start;
}
bool mye(Interval a, Interval b){
    return a.start == b.start;
}
class Solution {
public:
    int eraseOverlapIntervals(vector<Interval>& intervals) {
        if(intervals.empty()) return 0;
        sort(intervals.begin(), intervals.end(), compare);
        auto it = unique(intervals.begin(), intervals.end(), mye);
        int old_size = intervals.size();
        intervals.resize(distance(intervals.begin(),it));
        int ret = old_size - intervals.size();
        int next_end = intervals[0].end;
        for(int i = 1; i < intervals.size(); i++){
            if(intervals[i].start < next_end){
                ret++;
                next_end = min(intervals[i].end, next_end);
            }else
                next_end = max(intervals[i].end, next_end);
        }
        return ret;
    }
};