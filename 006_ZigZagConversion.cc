class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows==1) return s;
        string str[numRows];
        int i=0,j=0,len=s.size(),gap=numRows-2;
        while (i<len){
            for (j=0;i<len&&j<numRows;++j) str[j]+=s[i++];
            for (j=gap;i<len&&j>0;--j) str[j]+=s[i++];
        }
        string result;
        for (i=0;i!=numRows;++i)
            result+=str[i];
        return result;
    }
};