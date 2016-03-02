class Solution {
public:
    string countAndSay(int n) {
        if (n <= 0) return "";
		string result[2];
		int flag = 1;
		result[flag] = "1";
		for (int i = 1;i < n;++i)
		{
			int next = flag ^ 1;
			result[next].clear();
			int count = 1;
			int i = 1;
			char buf[32];
			for (;i < result[flag].size();++i)
			{
				if (result[flag][i] == result[flag][i - 1])
				{
					++count;
				}
				else
				{
					sprintf(buf,"%d",count);
					result[next] += buf;
					result[next] += result[flag][i - 1];
					count = 1;
				}
			}
			sprintf(buf,"%d",count);
			result[next] += buf;
			result[next] += result[flag][i - 1];
			flag = next;
		}
		return result[flag];
    }
};
