211_Add_and_Search_Word_-_Data_structure_design


题目大意
Design a data structure that supports the following two operations:

void addWord(word)
bool search(word)
search(word) can search a literal word or a regular expression string containing only letters a-z or .. A . means it can represent any one letter.

Note:
You may assume that all words are consist of lowercase letters a-z.



解决方案
用trie树解决，trie树有一个需要注意的点：就是在查找单词时，如果停在trie树的一个节点上，那个节点未必代表一个单词，可能只是一个单词的前缀，因此每个节点都要有一个标识位辅助判断当前位置是否是一个单词。





样例

For example:

addWord("bad")
addWord("dad")
addWord("mad")
search("pad") -> false
search("bad") -> true
search(".ad") -> true
search("b..") -> true

