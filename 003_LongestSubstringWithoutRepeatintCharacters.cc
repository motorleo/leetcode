class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> search(256,-1);
        int beg=-1,maxl=0;
        int end=0,length;
        for (;end!=s.size();++end){
            if (search[s[end]]>=beg){           //if repeat,undate beg.
                beg=search[s[end]];
            }
            search[s[end]]=end;
            length=end-beg;
            if (length>maxl) maxl=length;
        }
        return maxl;
    }
};