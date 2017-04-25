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
    ListNode* oddEvenList(ListNode* head) {
        ListNode *oddH = new ListNode(-1), *evenH = new ListNode(-1);
        ListNode *odd = oddH, *even = evenH;
        bool flag = true;
        while(head){
            if(flag){
                flag = false;
                odd->next = head;
                odd = odd->next;
            }
            else{
                flag = true;
                even->next = head;
                even = even->next;
            }
            head = head->next;
        }
        odd->next = evenH->next;
        even->next = NULL;
        return oddH->next;
    }
};