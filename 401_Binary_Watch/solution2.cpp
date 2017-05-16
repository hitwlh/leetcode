class Solution {
public:
    vector<string> readBinaryWatch(int num) {
        dfs(0, 0, num, 0, 0);
        return ret;
    }
private:
    vector<string> ret;
    void dfs(int hour, int minute, int num, int h_start, int m_start){
        if(num == 0){
            string h = to_string(hour), m = to_string(minute);
            if(minute < 10) m = "0" + m;
            ret.push_back(h + ":" + m);
            return;
        }
        if((m_start >= 6 && h_start >= 4) || num < 0)
            return;
        bitset<4> n_h(hour);
        bool flag1 = false, flag2 = false;
        if(h_start < 4){
            n_h.flip(h_start);
            if(n_h.to_ulong() > hour && n_h.to_ulong() < 12)
                flag1 = true;
        }
        bitset<6> n_m(minute);
        if(m_start < 6){
            n_m.flip(m_start);
            if(n_m.to_ulong() > minute && n_m.to_ulong() < 60)
                flag2 = true;
        }
        if(flag1 && flag2)
            dfs(n_h.to_ulong(), n_m.to_ulong(), num-2, h_start+1, m_start+1);
        if(flag1)
            dfs(n_h.to_ulong(), minute, num-1, h_start+1, m_start+1);
        if(flag2)
            dfs(hour, n_m.to_ulong(), num-1, h_start+1, m_start+1);
        dfs(hour, minute, num, h_start+1, m_start+1);
    }
};