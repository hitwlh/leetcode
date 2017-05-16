/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
struct my_Interval {
    int start, end, index;
    my_Interval() : start(0), index(-1) {}
    my_Interval(int s, int i) : start(s), index(i) {}
};
bool comp(my_Interval a, my_Interval b){
    if(a.start != b.start) return a.start < b.start;
    return a.index < b.index;
}
class Solution {
public:
    vector<int> findRightInterval(vector<Interval>& intervals) {
        vector<my_Interval> copy;
        int left, right, mid, size = intervals.size(), target;
        for(int i = 0; i < size; i++){
            my_Interval use(intervals[i].start, i);
            copy.push_back(use);
        }
        sort(copy.begin(), copy.end(), comp);
        vector<int> ret(intervals.size(), 0);
        for(int i = 0; i < size; i++){
            left = 0, right = size-1, target = intervals[i].end;
            while(left <= right){//闭区间[left, right]
                mid = left + (right - left) / 2;
                if(copy[mid].start < target) left = mid+1;
                else right = mid - 1;
            }
            if(copy[left].start < target) left++;
            if(left >= size) ret[i] = -1;
            else ret[i] = copy[left].index;
        }
        return ret;
    }
};