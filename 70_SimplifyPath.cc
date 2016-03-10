class Solution {
public:
    string simplifyPath(string path) {
        deque<string> queue;
		string::iterator iter = path.find(path.begin(),path.end(),'/');
		while (iter != path.end())
		{
			string::iterator iterEnd = path.find(iter + 1,path.end(),'/');
			string s(iter + 1,iterEnd);
			if (s == "..")
			{
				if (!queue.empty())
					queue.pop_back();
			}
			else if (!s.empty() && s != ".")
			{
				queue.push_back(s);
			}
			iter = iterEnd;
		}
		if (queue.empty())
			return "/";
		string result;
		while (!queue.empty())
		{
			result += '/' + queue.front();
			queue.pop_front();
		}
		return result;
    }
};
