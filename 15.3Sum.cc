class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) 
    {
        sort(nums.begin(),nums.end());
        int len=nums.size();
        vector<vector<int>> result;
        if (len<3) return result;
        for (int i=0;i<len-2&&nums[i]<1;++i) {
            unordered_set<int> search;
            int sum=0-nums[i];
            for (int j=i+1;j<len;++j) {
                int median=sum-nums[j];
                if (!search.count(median))
                    search.insert(nums[j]);
                else{                //匹配成功后跳过重复的数字
                    result.push_back({nums[i],median,nums[j]});
                    while (j+1<len&&nums[j]==nums[j+1]) ++j;
                }
            }
            while (i+1<len&&nums[i]==nums[i+1]) ++i;   //跳过重复数字
        }
        return result;
    }
};