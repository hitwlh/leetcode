//注意a要从0开始，以输入5为例，如果不从0开始，那就会用上3^2 + 4^2 = 25，这就返回2，错了
class Solution {
public:
    int numSquares(int n) {
        while (n % 4 == 0)
            n /= 4;
        if (n % 8 == 7)
            return 4;
        for (int a=0; a*a<n; ++a) {
            int b = sqrt(n - a*a);
            cout << a << " " <<  b << endl;
            if (a*a + b*b == n){
                if(a==0 || b==0) return 1;
                return 2;
            }
        }
        return 3;
    }
};