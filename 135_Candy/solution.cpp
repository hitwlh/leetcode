class Solution {
public:
    int candy(vector<int>& ratings) {
        vector<int> candies;
        int size = ratings.size();
        candies.assign(size, 1);
        for(int i = 1; i < size; i++)
            if(ratings[i] > ratings[i-1])
                candies[i] = candies[i-1]+1;
        for(int i = size-1; i > 0; i--)
            if(ratings[i-1] > ratings[i])
                candies[i-1] = max(candies[i]+1, candies[i-1]);
        int ret = 0;
        for(auto i: candies) ret += i;
        return ret;
    }
};