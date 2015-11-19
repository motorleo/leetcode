class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int len=strs.size();
        if (len==0) return "";
        if (len==1) return strs[0];
        string prefix;
        unsigned minlen=0;
        --minlen;
        for (int i=0;i!=len;++i){
            int temp=strs[i].size();
            if (temp<minlen) minlen=temp;
        }
        
        for (int i=0;i<minlen;++i)
        {
            int j;
            for (j=1;j<len;++j)
            {
                if (strs[j][i]!=strs[0][i])
                    break;
            }
            if (j!=len) break;
            prefix+=strs[0][i];
        }
        return prefix;
    }
};