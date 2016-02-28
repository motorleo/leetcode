
class Solution {
public:
    bool isValid(string s) 
	{
		stack<char> Parentheses;
		for (int i = 0;i < s.size();++i)
		{
		    if (s[i] == ')')
            {
				if (!Parentheses.empty() && Parentheses.top() == '(')
					Parentheses.pop();
				else
					return false;
            }
            else if (s[i] == '}')
            {
				if (!Parentheses.empty() && Parentheses.top() == '{')
					Parentheses.pop();
				else
					return false;
            }
            else if (s[i] == ']')
            {
				if (!Parentheses.empty() && Parentheses.top() == '[')
					Parentheses.pop();
				else
					return false;
            }
            else
            {
                Parentheses.push(s[i]);
            }
		}
		if (!Parentheses.empty()) return false;
		else return true;
    }
};
