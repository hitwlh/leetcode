class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        if(gas.empty()) return -1;
        vector<int> Gas, Cost;
        Gas.assign(gas.size(), 0);
        Cost.assign(gas.size(), 0);
        Gas[0] = gas[0], Cost[0] = cost[0];
        for(int i = 1; i < gas.size(); i++)
            Gas[i] = gas[i] + Gas[i-1];
        for(int i = 1; i < cost.size(); i++)
            Cost[i] = cost[i] + Cost[i-1];
        int next_start = 0;
        int flag = 0;
        for(int j = 0; j < gas.size(); j++){//0是起点
            if(Gas[j] < Cost[j]){
                flag = -1;
                next_start = j;
                break;
            }
        }
        if(flag == 0) return flag;
        for(int i = next_start; i < gas.size(); i = next_start){// i是起点
            flag = i;
            if(gas[i] < cost[i]){
                flag = -1;
                next_start++;
                continue;
            }
            for(int j = (i+1) % gas.size(); j != i; j = (j+1) % gas.size()){
                if(j > i){
                    if(Gas[j] - Gas[i-1] < Cost[j] - Cost[i-1]){
                        flag = -1;
                        next_start = j;
                        break;
                    }
                }else{
                    if(Gas[Gas.size()-1] - Gas[i-1] + Gas[j] < Cost[Cost.size()-1] - Cost[i-1] + Cost[j]){
                        flag = -1;
                        next_start = gas.size();
                        break;
                    }
                }
            }
            if(flag!=-1) return flag;
        }
        return flag;
    }
};