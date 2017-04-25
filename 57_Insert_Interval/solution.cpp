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
        if(intervals.empty()){
            intervals.push_back(newInterval);
            return intervals;
        }
        bool flag = false;
        for(int i = 0; i < intervals.size(); i++){
            if(intervals[i].end >= newInterval.start && intervals[i].start <= newInterval.end){
                    intervals[i].start = min(intervals[i].start, newInterval.start);
                    intervals[i].end = max(intervals[i].end, newInterval.end);
                    flag = true;
                    break;
            }
        }
        if(!flag){
            if(newInterval.start > intervals[intervals.size()-1].end){
                intervals.push_back(newInterval);
                return intervals;
            }else if(newInterval.end < intervals[0].start){
                intervals.insert(intervals.begin(), newInterval);
                return intervals;
            }
            for(int i = 0; i+1 < intervals.size(); i++){
                if(intervals[i].end < newInterval.start && newInterval.end < intervals[i+1].start){
                    intervals.insert(intervals.begin() + i + 1, newInterval);
                    return intervals;
                }
            }
            cout << "fuck!\n";exit(0);
        }
        for(int i = 0; i+1 < intervals.size(); i++){
            if(intervals[i].end >= intervals[i+1].start){
                intervals[i].end = max(intervals[i].end, intervals[i+1].end);
                intervals.erase(intervals.begin() + i + 1);
                i--;
            }
        }
        return intervals;
    }
};