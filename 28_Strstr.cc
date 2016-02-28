class Solution {
public:
    int strStr(string haystack, string needle) 
    {
        if (needle.empty()) return 0;
        int cmp = -1;
		int end = static_cast<int>(haystack.size() - needle.size());
        for (int i = 0;i <= end;++i)
        {
            int j = 0;
            for (;j < needle.size() && haystack[i + j] == needle[j];++j)
            {
            }
            if (j == needle.size())
            {
                cmp = i;
                break;
            }
        }
        return cmp;
    }
};
