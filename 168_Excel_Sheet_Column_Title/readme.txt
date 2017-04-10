168_Excel_Sheet_Column_Title


题目大意
Given a positive integer, return its corresponding column title as appear in an Excel sheet.



解决方案
就是进制转换的问题， 但是挺容易错的
这题是10进制转26进制，但是A不代表0而代表1
要考虑：
26转成26进制是Z
27转成26进制是AA
53转成26进制是BA

样例
    1 -> A
    2 -> B
    3 -> C
    ...
    26 -> Z
    27 -> AA
    28 -> AB 

