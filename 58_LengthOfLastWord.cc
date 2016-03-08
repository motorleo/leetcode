class Solution {
public:
    int lengthOfLastWord(string s) {
		int i = s.size() - 1;
		for (;i >= 0;--i)
		{
			if (s[i] != ' ')
				break;
		}
		if (i == -1) return 0;
		int end = i;
		for (;i >= 0;--i)
		{
			if (s[i] == ' ')
				break;
		}
		return end - i;
    }
};
