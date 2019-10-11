struct node{
    node(int v, int i): val(v), index(i){};
    int val, index;
};

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<node> m;
        for(int i = 0; i < nums.size(); i++)
            m.push_back(node(nums[i], i));
        sort(m.begin(), m.end(), [](node a, node b){return a.val < b.val;});
        int left = 0, right = m.size()-1;
        while(left < right){
            if(m[left].val + m[right].val == target) return {m[left].index, m[right].index};
            else if(m[left].val + m[right].val < target) left++;
            else right--;
        }
    }
};
