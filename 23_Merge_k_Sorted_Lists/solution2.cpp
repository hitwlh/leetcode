/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
struct ListNodeComp {
    bool operator () (const ListNode *n1, const ListNode *n2) const {
        return n1->val > n2->val;
    }
};
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode *HEAD = new ListNode(-1);
        ListNode *q = HEAD;
        for(int i = 0; i < lists.size(); i++){
            if(lists[i])
                my_pq.push(lists[i]);
        }
        while(!my_pq.empty()){
            ListNode *p = my_pq.top();
            my_pq.pop();
            q ->next = p;
            q = q->next;
            if(p->next)
                my_pq.push(p->next);
        }
        return HEAD->next;
    }
private:
    priority_queue<ListNode*, vector<ListNode*>, ListNodeComp> my_pq;
};