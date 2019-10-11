/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    int numComponents(ListNode* head, vector<int>& G) {
        for(auto g: G) nums[g] = true;
        int ret = 0, now = 0;
        while(head){
            if(nums.count(head->val)){
                if(!now) ret++;
                now++;
            }else
                now = 0;
            head = head->next;
        }
        return ret;
    }
private:
    unordered_map<int, bool> nums;
};