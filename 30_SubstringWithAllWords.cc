
bool compareKString(char* lhs,char* rhs,int length)
{
	if (length > 0)
	{
		for (int i = 0;i < length;++i)
		{
			if (lhs[i] != rhs[i])
				return false;
		}
		return true;
	}
	return false;
}

bool isSubstring(char* s,vector<string>& words)
{
	int length = words[0].size();
	bool check[words.size()];
	memset(check,false,sizeof(check));
	for (int i = 0;i < words.size();++i)
	{
		char* current = s + i * length;
		bool iscmp = false;
		for (int j = 0;j < words.size();++j)
		{
			if (!check[j] && compareKString(current,&words[j][0],length))
			{
				check[j] = true;
				iscmp = true;
				break;
			}
		}
		if (!iscmp) return false;
	}
	return true;
}

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
		vector<int> result;
		if (s.empty() || words.empty()) return result;
		int singleLength = words[0].size();
		int wordsLength = singleLength * words.size();
		int end = static_cast<int>(s.size() - wordsLength);
		for (int i = 0;i < end;i += singleLength)
		{
			if (isSubstring(&s[i],words))
			{
				result.push_back(i);
			}
		}
		return result;
    }
};
