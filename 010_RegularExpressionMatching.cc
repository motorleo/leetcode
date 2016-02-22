bool match(const char* s,const char* p){
    if (*p=='\0') return *s=='\0';
    //next char != '*'
    if (*(p+1)!='*')
    {
        return (*p==*s||(*p=='.'&& *s!='\0'))&&match(s+1,p+1);
    }
    else    //next char == '*'
    {
        while ((*p==*s||*p=='.')&& *s!='\0')
        {
            if (match(s,p+2)) return true;
            ++s;
        }
    }
    return match(s,p+2);
}

class Solution {
public:
    bool isMatch(string s, string p) {
        s+='\0';
        p+='\0';
        return match(&s[0],&p[0]);
    }
};