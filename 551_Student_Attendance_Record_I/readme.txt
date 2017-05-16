551_Student_Attendance_Record_I


题目大意
You are given a string representing an attendance record for a student. The record only contains the following three characters:
'A' : Absent.
'L' : Late.
'P' : Present.
A student could be rewarded if his attendance record doesn't contain more than one 'A' (absent) or more than two continuous 'L' (late).
You need to return whether the student could be rewarded according to his attendance record.





解决方案
题目翻译：一个字符串，A不超过1个，或者L不连续3次出现就返回true
挺简单的，毫无算法可言







样例
Example 1:
Input: "PPALLP"
Output: True
Example 2:
Input: "PPALLL"
Output: False

