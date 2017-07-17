class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> ret;
        if(words.empty())
            return ret;
        if(words[0].empty()){
            ret.push_back(string(maxWidth, ' '));
            return ret;
        }
        for(int i = 0, now = i; i < words.size(); i = now+1){
            now = i;//[words[i], words[now]]这些单词是要写在同一行的
            int length = words[i].length(), true_length, word_count;
            while(now + 1 < words.size() && length + words[now+1].length() + 1 <= maxWidth)
                length += words[++now].length() + 1;//length是[words[i], words[now]]里所有单词的字符数
            word_count = now - i + 1;//单词数
            if(word_count == 1){//只有1个单词的时候直接写完填满空格返回，如果不处理，在后面的right_space_count时就除零了
                ret.push_back(words[i] + string(maxWidth - words[i].length(), ' '));
                continue;
            }
            string push;
            if(now + 1 != words.size()){
                true_length = length - word_count + 1;
                int total_space = maxWidth - true_length;
                int right_space_count = total_space / (word_count-1);//右边的单词间用right_space_count个空格，左边的用right_space_count+1个空格
                int start = i+1;
                push = words[i];
                int left_part = total_space - right_space_count * (word_count - 1), space;//words[i+1], ..., word[i+left_part前用right_space_count+1个空格(也就是用left_part标识左边)
                while(start <= now){
                    if(start <= i + left_part) space = right_space_count + 1;
                    else space = right_space_count;
                    push += string(space, ' ') + words[start++];
                }   
            }else{
                int start = i;
                while(start <= now)
                    push += words[start++] + " ";
                push = push + string(maxWidth - push.size(), ' ');
            }
            ret.push_back(push);
        }
        return ret;
    }
};