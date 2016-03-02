class Solution {
public:
    void dfs(vector<int>& candidates,
            int index,
            int target,
            vector<vector<int>>& result,
            vector<int>& path)
    {
        if (target == 0)
        {
            result.push_back(path);
        }
        else if (target < 0)
        {
            return;
        }
        else
        {
            for (int i = index;i < candidates.size();++i)
            {
                path.push_back(candidates[i]);
                dfs(candidates,i + 1,target - candidates[i],result,path);
                path.pop_back();
                while (i < candidates.size() - 1 && candidates[i] == candidates[i + 1])
                    ++i;
            }
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        if (candidates.empty()) return result;
        sort(candidates.begin(),candidates.end());
        vector<int> path;
        dfs(candidates,0,target,result,path);
        return result;
    }
};

