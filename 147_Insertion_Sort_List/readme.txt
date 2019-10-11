147_Insertion_Sort_List


题目大意
Sort a linked list using insertion sort.

解决方案

pair<ListNode*, ListNode*> insert(ListNode *left, ListNode *right, ListNode *insert)函数
将insert插入到[left, right]区间
问题在于这个函数必须返回一个区间，因为插入可能插在最前面，将left修改，也可能插入在最后，将right修改，因此直接返回这个区间

one_time_attention:
主函数的break需要注意，break的条件是没有需要插入的元素了，一开始写的是while(right),但是right其实永远不会是空的，因为insert返回的right不会是NULL


样例


