class Solution {
public:
    int reverse(int x) {
        bool nagetive=false;
        int num=x,result=0;
        if (x<0){
            num=0-num;
            nagetive=true;
        }
        while (num/10!=0){
            result=result*10+num%10;
            num=num/10;
        }
        int test=result;
        result=result*10+num%10;
        if (result/10!=test)
            return 0;
        if (nagetive)
            result=0-result;
        return result;
    }
};