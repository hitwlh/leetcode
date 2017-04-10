3_Longest_Substring_Without_Repeating_Characters

题目大意
给一个字符串，找出最长的不带重复字符的子串

解决方案
设置一个best变量，从左到右顺序遍历，当遍历到s[i]，时，best中存储的是从s[0]到s[i]中最长的子串长度。
用left_index作为一个子串的起始下标，当遍历到s[i]时，s[left_index]...s[i-1]是以s[i-1]作为最右端，所能获得的最长不重复子串
当遍历进行到s[i]时，如果s[left_index]...s[i-1]中无s[i]，则s[left_index]...s[i]是以s[i]作为最右端，所能获得的最长不重复子串
如果s[left_index]...s[i-1]中有s[i]，那么，s[get[s[i]]+1]...s[i]是以s[i]作为最右端，所能获得的最长不重复子串。此时，将max{best,i-get[s[i]]}设置为新的best即可


样例
Given "abcabcbb", the answer is "abc", which the length is 3.
