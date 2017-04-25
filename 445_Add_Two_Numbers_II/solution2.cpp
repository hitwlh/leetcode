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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(!l1) return l2;
        if(!l2) return l1;
        ListNode *l1_s = l1, *l2_s = l2;
        while(l1_s && l2_s){
            l1_s = l1_s->next;
            l2_s = l2_s->next;
        }
        if(l2_s) swap(l1, l2), swap(l1_s, l2_s);
        ListNode *fenjie = l1;
        while(l1_s) l1_s = l1_s->next, fenjie = fenjie->next;
        ListNode *right = addTwo_equal(fenjie, l2);
        ListNode *left = addone(l1, fenjie); 
        ListNode *ret;
        if(left){
            if(addone_right) addone_right->next = right;
            if(carry){
                ret = new ListNode(1);
                ret->next = left;
                return ret;
            }
            return left;
        }else{
            if(carry){
                ret = new ListNode(1);
                ret->next = right;
                return ret;
            }else
            return right;
        }
    }
private:
    ListNode* addone_right;
    ListNode* addone(ListNode* l1, ListNode* end){
        if(l1 == end) return NULL;
        ListNode *ret, *next;
        if(l1->next == end){
            if(l1->val + carry > 9){
                ret = new ListNode(l1->val + carry - 10);
                carry = 1;
            }else{
                ret = new ListNode(l1->val + carry);
                carry = 0;
            }
            addone_right = ret;
            return ret;
        }else{
            next = addone(l1->next, end);
            if(l1->val + carry > 9){
                ret = new ListNode(l1->val + carry - 10);
                carry = 1;
            }else{
                ret = new ListNode(l1->val + carry);
                carry = 0;
            }
            ret->next = next;
            return ret;
        }
    }
    ListNode* addTwo_equal(ListNode* l1, ListNode* l2){
        ListNode *ret, *next;
        if(!l1->next && !l2->next){
            if(l1->val + l2->val + carry > 9){
                ret = new ListNode(l1->val + l2->val + carry - 10);
                carry = 1;
            }else{
                ret = new ListNode(l1->val + l2->val + carry);
                carry = 0;
            }
            return ret;
        }
        else{
            next = addTwo_equal(l1->next, l2->next);
            if(l1->val + l2->val + carry > 9){
                ret = new ListNode(l1->val + l2->val + carry - 10);
                carry = 1;
            }else{
                ret = new ListNode(l1->val + l2->val + carry);
                carry = 0;
            }
            ret->next = next;
            return ret;
        }
    }
    int carry = 0;
};