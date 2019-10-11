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
    ListNode* insertionSortList(ListNode* head) {
        ListNode* HEAD = new ListNode(-1);
        HEAD->next = head;
        ListNode* last = head;//last表示有序序列的最后一个元素
        while(last){
            ListNode* q = last->next;
            if(!q) break;
            last->next = q->next;
            ListNode* now = HEAD;//左开右闭
            while(now != last and now->next->val < q->val)
                now = now->next;
            q->next = now->next;
            now->next = q;
            last = (last->val >= q->val) ? last : q;//注意，如果q的val等于last节点，那么q会插在last左边，因此如果last->val==q->val,last应该保持不变
        }
        return HEAD->next;
    }
};