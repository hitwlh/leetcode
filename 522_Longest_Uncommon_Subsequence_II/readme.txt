522_Longest_Uncommon_Subsequence_II


题目大意
Given a list of strings, you need to find the longest uncommon subsequence among them. The longest uncommon subsequence is defined as the longest subsequence of one of these strings and this subsequence should not be any subsequence of the other strings.

A subsequence is a sequence that can be derived from one sequence by deleting some characters without changing the order of the remaining elements. Trivially, any string is a subsequence of itself and an empty string is a subsequence of any string.

The input will be a list of strings, and the output needs to be the length of the longest uncommon subsequence. If the longest uncommon subsequence doesn't exist, return -1.

Note:

All the given strings' lengths will not exceed 10.
The length of the given list will be in the range of [2, 50].


解决方案
这题的数据量很小，基本上不需要考虑时间问题。但是妙处在于这题的子串判断函数：
bool issub(string a, string b){
        if(a.length() < b.length()) swap(a, b);
        int index_a = 0, index_b = 0;
        while(index_a < a.length()){
            if(index_b >= b.length()) return true;
            if(a[index_a] == b[index_b])
                index_b++;
            index_a ++;
        }
        if(index_b >= b.length()) return true;
        return false;
    }
注意while循环最外层还有if(index_b >= b.length()) return true;


如果想优化应该是要去重：某个长度的字符串vector内有若干重复string，当然这题数据量很小，不处理也很ok

样例
Example 1:
Input: "aba", "cdc", "eae"
Output: 3

