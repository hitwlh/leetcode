class Solution {
public:
    vector<string> readBinaryWatch(int num) {
        vector<vector<string>> hour(4),minute(6);
        for(int i = 0; i < 12; i++)
            hour[hammingWeight(i)].push_back(to_string(i));
        for(int i = 0; i < 60; i++){
            string str = to_string(i);
            if(i < 10) str = "0" + str;
            minute[hammingWeight(i)].push_back(str);
        }
        vector<string> ret;
        for(int i = 0; i <= num && i < 4; i++){
            if(num - i < 6)
                for(auto h: hour[i])
                    for(auto m: minute[num - i])
                        ret.push_back(h+":"+m);
        }
        return ret;
    }
private:
    int hammingWeight(int i){
        int sum = 0;
        while(i){
            i &= (i-1);
            sum++;
        }
        return sum;
    }
};








class Solution {
public:
    vector<string> readBinaryWatch(int num) {
        vector<string> times;
        for (int i = 0; i < 12; i++) {
            for (int j = 0; j < 60; j++) {
                if (hammingWeight(i) + hammingWeight(j) == num)
                    times.push_back(to_string(i) + (j < 10? ":0": ":") + to_string(j));
            }
        }
        return times;
    }
private:
    int hammingWeight(int i){
        int sum = 0;
        while(i){
            i &= (i-1);
            sum++;
        }
        return sum;
    }
};







class Solution {
public:
    vector<string> readBinaryWatch(int num) {
        vector<string> times;
        for (int i = 0; i < 12; i++) {
            bitset<4> h((size_t) i);
            for (int j = 0; j < 60; j++) {
                bitset<6> m((size_t) j);
                if (h.count() + m.count() == num)
                    times.push_back(to_string(i) + (j < 10? ":0": ":") + to_string(j));
            }
        }
        return times;
    }
};