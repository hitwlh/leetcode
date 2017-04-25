117_Populating_Next_Right_Pointers_in_Each_Node_II


题目大意
Follow up for problem "Populating Next Right Pointers in Each Node".
What if the given tree could be any binary tree? Would your previous solution still work?

解决方案
在116题solution2的基础上，增加一个avaliable_next函数，也就是说root->right->next应该是下一个有左或右儿子的结点的左或右儿子，而不是简单
if(root->next) root->right->next = root->next->left;

样例


