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
    vector<ListNode*> splitListToParts(ListNode* root, int k) {
        ListNode* p = root;
        int len = 0, size;
        while(p){
            len++;
            p = p->next;
        }
        size = len / k;
        int left_part = len - k * size;
        int right_part = k - left_part;
        vector<ListNode*> ret;
        p = root;
        while(left_part){
            left_part--;
            ret.push_back(p);
            p = getk(p, size+1);
        }
        while(right_part){
            right_part--;
            ret.push_back(p);
            p = getk(p, size);
        }
        return ret;
    }
private:
    ListNode* getk(ListNode* root, int k){
        //if(k == 0) return NULL;
        if(!root) return root;
        ListNode* p = root;
        while(--k)
            p = p->next;
        ListNode* next = p->next;
        p->next = NULL;
        return next;
    }
};