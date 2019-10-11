/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        RandomListNode *p = head, *Head = NULL;
        while(p){
            p->next = copy(p);
            p = p->next->next;
        }
        p = head;
        if(head) Head = head->next;
        while(p){
            if(p->random) p->next->random = p->random->next;
            p = p->next->next;
        }
        p = head;
        while(p){
            RandomListNode *q = p->next->next;
            if(p->next->next) p->next->next = q->next;
            p->next = q;
            p = q;
        }
        return Head;
    }
private:
    RandomListNode *copy(RandomListNode *head) {
        RandomListNode * ne = new RandomListNode(head->label);
        ne->next = head->next;
        ne->random = head->random;
        return ne;
    }
};