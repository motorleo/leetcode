class Solution {
public:
    bool isPalindrome(int x) {
        if (x<0) return false;
        int base=1;
        int num=x;
        while (num/10) {
            base*=10;
            num/=10;
        }
        num=x;
        while (num){                         //由base>=10变成num，时间从164ms变为76ms，
            int left=num/base,right=num%10;  //这是因为base作为条件时，寄存器循环相关，除法变为关键路径。
            if (left!=right) return false;   //num作为条件
            num%=base;
            num/=10;
            base/=100;
        }
        return true;
    }
};