class Solution {
public:
    string intToRoman(int num) {
        struct change{                      
            change(int v,const string c):value(v),ch(c){}
            int value;
            string ch;
            int t=0;
            
            void make_t(int& num){    
                t=num/value;
                num%=value;
            }
        };
        vector<change> c=
        {
            change(1000,"M"),
            change(900,"CM"),
            change(500,"D"),
            change(400,"CD"),
            change(100,"C"),
            change(90,"XC"),
            change(50,"L"),
            change(40,"XL"),
            change(10,"X"),
            change(9,"IX"),
            change(5,"V"),
            change(4,"IV"),
            change(1,"I")
        };
        int clen=c.size();
        for (int i=0;i!=clen;++i)  
            c[i].make_t(num);
            
        string result;
        for (int i=0;i!=clen;++i)
        {
            for (int j=0;j!=c[i].t;++j)
            {
                result+=c[i].ch;
            }
        }
        return result;
    }
};
