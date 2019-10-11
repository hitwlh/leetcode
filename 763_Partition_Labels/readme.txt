763_Partition_Labels


题目大意
A string S of lowercase letters is given. We want to partition this string into as many parts as possible so that each letter appears in at most one part, and return a list of integers representing the size of these parts.
Note:

S will have length in range [1, 500].
S will consist of lowercase letters ('a' to 'z') only.



解决方案
一个窗口内出现的所有字符，必须包含其最右侧，因此用一个hash表存储每个字符后一次出现的位置。




样例
Example 1:
Input: S = "ababcbacadefegdehijhklij"
Output: [9,7,8]
Explanation:
The partition is "ababcbaca", "defegde", "hijhklij".
This is a partition so that each letter appears in at most one part.
A partition like "ababcbacadefegde", "hijhklij" is incorrect, because it splits S into less parts.

