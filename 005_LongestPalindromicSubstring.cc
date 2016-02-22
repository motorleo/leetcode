class Solution {
public:
    string longestPalindrome(string s) {
		string result;
		int k = 0, begin, end;       //end-begin
		int currentLength = 1;
		if (s.size())
			result = s[0];
		int len = s.size();
		for (int i = 1; i<len; ++i) {
			if (s[i] == s[i - 1]) {
				begin = i - 1;
				end = i;
				while (begin>=0 && end<len&&s[begin] == s[end]) {
					--begin;
					++end;
				}
				++begin;
				--end;
				if (currentLength<end - begin + 1) {
					currentLength = end - begin + 1;
					result.assign(&s[begin], currentLength);
				}
			}
			if (i != 1 && s[i] == s[i - 2]) {
				begin = i - 2;
				end = i;
				while (begin>=0 && end<len&&s[begin] == s[end]) {
					--begin;
					++end;
				}
				++begin;
				--end;
				if (currentLength<end - begin + 1) {
					currentLength = end - begin + 1;
					result.assign(&s[begin], currentLength);
				}
			}

		}
		return result;
	}
};