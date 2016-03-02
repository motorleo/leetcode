
bool Valid(char* s,int end)
{
	stack<char> stack(end + 1);
	for (int i = 0;i <= end;++i)
	{
		if (s[i] == ')' && stack.top() != '(')
			return false;
		else
			stack.push(s[i]);
	}
	if (stack.empty()) return true;
	else return false;
}

int maxPareLength(char* s,int length)
{
	int LCount = 0;
	int RCount = 0;
	for(int i = 0;i < length;++i)
	{
		if (s[i] == '(')
			++LCount;
		else if (s[i] == ')')
			++RCount;
		else
			return -1;
	}
	int result = 0;
	int end = length - 1;
	while(LCount > 0 && RCount > 0)
	{
		if (LCount == RCount && Valid(s,end))
		{
			result = end + 1;
			break;
		}
		else
		{
			if (s[end] == '(')
				--LCount;
			else
				--RCount;
		}
	}
	return result;
}

class Solution {
public:
    int longestValidParentheses(string s) {
        if (s.empty()) return 0;
		int MaxValid = 0;
		int i = 0;
		while (i < s.size() - MaxValid)
		{
			if (s[i] == '(')
			{
				int ValidLength = maxPareLength(&s[i],s.size() - i);
				MaxValid = max(ValidLength,MaxValid);
				if (ValidLength)
					i += ValidLength;
				else
					++i;
			}
			else
			{
				++i;
			}
		}
		return MaxValid;
    }
};//TLE

class Solution {
public:
    int longestValidParentheses(string s) {
        bool *a = new bool[s.length()];
        memset(a, false, s.length());
        stack<int> st;
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == '(') {
                st.push(i);
            } else if (s[i] == ')' && !st.empty()) {
                a[i] = true;
                a[st.top()] = true;
                st.pop();
            }
        }
        int max_len = 0, cur_len = 0;
        for (int i = 0; i < s.length(); ++i) {
            if (a[i]) ++cur_len;
            else cur_len = 0;
            max_len = max(max_len, cur_len);
        }
        return max_len;
    }
};
