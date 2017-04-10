206_Reverse_Linked_List


题目大意
Reverse a singly linked list.

解决方案
1.非递归，在solution1.cpp
顺序遍历这个链表，依次将碰到的元素置为头。
定义一个now，初始化为head->next(如果head!=NULL)
定义一个HEAD
if(!head)
    return head->next;
now = head->next;
while(now!=NULL){
    head->next = now->next;
    now->next = HEAD;
    HEAD = now;
    now = head->next;
}


2.递归，在solution2.cpp
reverseList(head->next)会将head->next变成段尾，因此将head添加进去的办法是head->next->next = head;head->next = NULL;
到了递归终止的地方返回的就是本身，因此这个本身就是每个reverseList的头

ListNode* reverseList(ListNode* head) {
        if(!head || !head->next)
            return head;
        ListNode* new_head = reverseList(head->next);
        head->next->next = head;
        head->next = NULL;
        return new_head;
    }
样例


