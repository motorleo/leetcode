
int getnum(char c){
    switch (c){
        case 'M': return 1000;
        case 'D': return 500;
        case 'C': return 100;
        case 'L': return 50;
        case 'X': return 10;
        case 'V': return 5;
        case 'I': return 1;
    }
    return 0;
}


class Solution {
public:
    int romanToInt(string s) {
        int len=s.size(),result=0;
        int last_num=0;
        for (int i=0;i<len;++i){
            int current=getnum(s[i]);
            if (current>last_num)                //如果比last_num大则减之
                result-=last_num;
            else
                result+=last_num;
            last_num=current;
        }
        result+=last_num;
        return result;
    }
};