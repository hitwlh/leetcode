class Solution {
public:
    int divide(int fenzi, int fenmu) {
        //if(fenzi == 0)
          //  return 0;
        //if(fenmu == 0)
          //  return INT_MAX;
        if(fenzi == INT_MIN && fenmu == -1)
            return INT_MAX;
        int negative_flag = -1;
        if((fenzi > 0 && fenmu > 0) ||(fenzi<0 && fenmu < 0))
            negative_flag = 1;
        long long ll_fenzi = fabs(fenzi);
        long long ll_fenmu = fabs(fenmu);
        long long tmp_fenzi, tmp_fenmu;
        long long result = 0;
        int flag;
        while(ll_fenzi != 0){
            flag = 0;
            tmp_fenzi = ll_fenzi;
            tmp_fenmu = ll_fenmu;
            while(tmp_fenmu < tmp_fenzi){
                flag ++;
                tmp_fenmu = tmp_fenmu << 1;
            }
            if(flag || tmp_fenmu==tmp_fenzi){
                //cout << "flag is: " << flag << endl;
                if(flag == 0){
                    result += 1;
                    ll_fenzi -= ll_fenmu;
                }
                else{
                    result += (1 << (flag-1));
                    ll_fenzi -= tmp_fenmu >> 1;
                }
            }
            else
                ll_fenzi = 0;
            //cout << "result is: " << result << ", ll_fenzi is:" << ll_fenzi << endl;
        }
        return result * negative_flag;
    }
};