140_Word_Break_II


题目大意
Given a non-empty string s and a dictionary wordDict containing a list of non-empty words, add spaces in s to construct a sentence where each word is a valid dictionary word. You may assume the dictionary does not contain duplicate words.

Return all such possible sentences.

解决方案
139. Word Break的进阶版本
其实就是从后往前搜索的时候搜索成功不能直接break，而是要把前面所有都搜索完并记录结果
有个要注意的就是有可能没有解，但是会尝试太多次而导致空间爆炸
因此先直接调用139. Word Break的函数判断是否有解，有的话再找解，没有就可以返回了。

样例
For example, given
s = "catsanddog",
dict = ["cat", "cats", "and", "sand", "dog"].

A solution is ["cats and dog", "cat sand dog"].



