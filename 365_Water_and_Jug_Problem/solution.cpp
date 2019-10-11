class Solution {
public:
    bool canMeasureWater(int x, int y, int z) {
        if(!z) return true;
        if(!x) return y == z;
        if(!y) return x == z;
        int k = gcd(x, y);
        return z % k == 0 && z <= x + y;
    }
private:
    int gcd(int x, int y){
        while(x % y != 0){
            int t = x;
            x = y;
            y = t % x;
        }
        return y;
    }
};