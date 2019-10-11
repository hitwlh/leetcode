class Solution {
public:
    int divide(int fenzi, int fenmu) {
        if(fenzi == INT_MIN && fenmu == -1)
            return INT_MAX;
        bool negative_flag = ((fenzi > 0 && fenmu > 0) || (fenzi<0 && fenmu < 0));
        long ll_fenzi = fabs(fenzi), ll_fenmu = fabs(fenmu);
        long tmp_fenmu = ll_fenmu;
        int result = 0, most = 0;
        while(ll_fenzi >= tmp_fenmu){
            most++;
            tmp_fenmu <<= 1;
        }
        while(ll_fenzi >= ll_fenmu){
            while(tmp_fenmu > ll_fenzi){
                most--;
                tmp_fenmu >>= 1;
            }
            if(most == 0){
                if(ll_fenzi >= tmp_fenmu)
                    result += 1;
                ll_fenzi -= ll_fenmu;
                break;
            }
            else{
                result += (1 << most);
                ll_fenzi -= (tmp_fenmu);
            }
            
        }
        return negative_flag ? result : -result;
    }
};