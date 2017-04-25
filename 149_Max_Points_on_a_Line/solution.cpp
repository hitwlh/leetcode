/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
class Solution {
public:
    int maxPoints(vector<Point>& points) {
        if(points.empty()) return 0;
        int ret = 0;
        unordered_map<double, int> mymap;//double是斜率，int是这个斜率出现过多少次
        for(int i = 0; i < points.size(); i++){
            mymap.clear();
            int tmp = 0;//tmp是斜率为无穷大出现过多少次
            int self = 0;//self是同样点重合多少次
            for(int j = 0; j < points.size(); j++){
                if(points[j].y == points[i].y){
                    if(points[j].x != points[i].x)
                        tmp++;
                    else
                        self++;
                    continue;
                }
                double a = points[j].x - points[i].x, b = points[j].y - points[i].y;
                mymap[a/b]++;
            }
            for(auto i: mymap) ret = max(ret, i.second+self);
            ret = max(ret, tmp+self);
        }
        return ret;
    }

};