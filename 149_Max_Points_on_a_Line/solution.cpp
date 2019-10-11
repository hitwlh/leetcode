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
        int ret = 0;
        for(auto i: points)
            ret = max(inpoints(points, i), ret);
        return ret;
    }
private:
    int inpoints(vector<Point>& points, Point vertex){
        unordered_map<string, int> map;
        int same = 0, tmp1 = 0, tmp2 = 0;
        for(auto point: points){
            if(point.x == vertex.x && point.y == vertex.y){
                same++;
                continue;
            }
            if(point.y == vertex.y) tmp1++;
            if(point.x == vertex.x) tmp2++;
            else{
                int x = gcd(point.y - vertex.y, point.x - vertex.x);//必须有最大公约数，否则18/4!=9/2的情况会出现
                map[to_string((point.y - vertex.y) / x) + "," + to_string((point.x - vertex.x) / x)]++;
            }
        }
        int ret = 0;
        for(auto i: map)
            ret = max(ret, i.second);
        return max(max(ret, tmp1), tmp2) + same;
    }
    int gcd(int x, int y){
        while(x % y != 0){
            int t = x;
            x = y;
            y = t % x;
        }
        return y;
    }
};