class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        my_lists = lists;
        return my_mergeKLists(0, lists.size()-1);
    }
    ListNode* my_mergeKLists(int left, int right){
        if(left > right) return NULL;
        if(left == right) return my_lists[left];
        return mergeTwoLists(my_mergeKLists(left, left+(right-left)/2), my_mergeKLists(left+(right-left)/2+1, right));
    }
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* l1_head = l1, *l2_head = l2, *Head = new ListNode(-1);
        ListNode* ret = Head;
        while(l1 && l2){
            if(l1->val < l2->val){
                Head->next = l1;
                l1 = l1->next;
            }
            else{
                Head->next = l2;
                l2 = l2->next;
            }
            Head = Head -> next;
        }
        if(!l1) Head->next = l2;
        else Head->next = l1;
        return ret->next;
    }
private:
    vector<ListNode*> my_lists;
};