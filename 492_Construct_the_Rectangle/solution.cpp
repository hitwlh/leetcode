class Solution {
public:
    vector<int> constructRectangle(int area) {
        for(int i = sqrt(area); i >= 1; i--){
            if(area / i * i == area)
                return {area/i, i};
        }
    }
};