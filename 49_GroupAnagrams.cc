class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string,multiset<string>> result;
		for (int i = 0;i < strs.size();++i)
		{
			string temp = strs[i];
			sort(temp.begin(),temp.end());
			if (result.find(temp) == result.end())
			{
				multiset<string> tempSet;
				tempSet.insert(strs[i]);
				result[temp] = tempSet;
			}
			else
			{
				result[temp].insert(strs[i]);
			}
		}
		map<string,multiset<string>>::iterator iter = result.begin();
		vector<vector<string>> res;
		for (;iter != result.end();++iter)
		{
			vector<string> tempVec(iter->second.begin(),iter->second.end());
			res.push_back(tempVec);
		}
		return res;
    }
};
