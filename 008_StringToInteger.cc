class Solution {
public:
    int myAtoi(string str) {
        int begin=0,end=str.size()-1;
        if (end<0)
            return 0;
        int zero='0';
        bool nagetive=false;
        while (begin<=end&&str[begin]==' ')  ++begin;    //去除首空格。
        if (str[begin]=='+'||str[begin]=='-'){               //读取符号位。
            if (str[begin]=='-')
                nagetive=true;
            ++begin;
        }
        int result=0;
        while (begin<=end){         //转换
            int n=str[begin]-zero;
            if (n>9||n<0){
                if (nagetive) result=~result+1;
                return result;
            }  
            int test=result*10+n;
            if (test/10!=result){
                if (!nagetive) 
                    return 0x7fffffff;                //上溢return INT_MAX,下溢INT_MIN。
                else
                    return 0x7fffffff+1;
            }
            result=test;
            ++begin;
        }
        if (nagetive) result=~result+1;
        return result;
    }
};