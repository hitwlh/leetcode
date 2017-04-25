/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
bool Coompare(Interval &a, Interval &b){
        return a.start < b.start;
}
class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        if(intervals.size() <= 1) return intervals;
        sort(intervals.begin(), intervals.end(), Coompare);
        for(int i = 0; i < intervals.size()-1; i++){
            if(intervals[i].end >= intervals[i+1].start){
                intervals[i].end = max(intervals[i].end, intervals[i+1].end);
                intervals.erase(intervals.begin()+i+1);
                i--;
            }
        }
        return intervals;
    }
};