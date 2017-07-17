class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if(n > 10) return countNumbersWithUniqueDigits(10);
        MAX = pow(10, n);
        used.assign(10, false);
        int count = 1;
        for(int i = 1; i < 10; i++){
            used[i] = true;
            count += search(i);
            used[i] = false;
        }
        return count;
    }
private:
    int search(long prev){
        int count = 0;
        if(prev < MAX) count++;
        else return count;
        for(int i = 0; i < 10; i++){
            if(!used[i]){
                used[i] = true;
                count += search(10 * prev + i);
                used[i] = false;
            }
        }
        return count;
    }
    vector<bool> used;
    long MAX;
};