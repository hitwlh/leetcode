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
class Solution {
public:
    int eraseOverlapIntervals(vector<Interval>& intervals) {
        if(intervals.empty()) return 0;
        sort(intervals.begin(), intervals.end(), compare);
        int i = 1, ret = 0, end = intervals[0].end;
        while(i < intervals.size()){
            if(intervals[i].start < end){
                end = min(end, intervals[i].end);
                ret++;
            }else{
                end = intervals[i].end;
            }
            i++;
        }
        return ret;
    }
};