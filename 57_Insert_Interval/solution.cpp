/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        int i;
        for(i = 0; i < intervals.size(); i++){
            if(intervals[i].start < newInterval.start) ;
            else break;
        }
        intervals.insert(intervals.begin()+i, newInterval);
        if(intervals.size() <= 1) return intervals;
        //sort(intervals.begin(), intervals.end(), [](Interval &a, Interval &b){return a.start < b.start;});
        for(i = 0; i < intervals.size()-1; i++){
            if(intervals[i].end >= intervals[i+1].start){
                intervals[i].end = max(intervals[i].end, intervals[i+1].end);
                intervals.erase(intervals.begin()+i+1);
                i--;
            }
        }
        return intervals;
    }
};