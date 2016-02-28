void generateCore(vector<string>& result,string s,int left,int right)
{
	if (left == 0 && right == 0)
	{
		result.push_back(s);
	}
	else
	{
		if (left)
		{
			generateCore(result,s + '(',left - 1,right);
		}
		if (left < right)
		{
			generateCore(result,s + ')',left,right - 1);
		}
	}
}

class Solution {
public:
    vector<string> generateParenthesis(int n) 
	{
		vector<string> result;
		if (n > 0)
		{
			generateCore(result,"",n,n);
		}
		return result;
    }
};
