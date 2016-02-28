


class Solution {

public:

    vector<vector<int>> fourSum(vector<int>& nums, int target) 
	{
        vector<vector<int> > result;
		if (nums.size() < 4) return result;
		sort(nums.begin(),nums.end());
		set<vector<int> > unique;
		for (int i = 0;i < nums.size() - 3;++i)
		{
			int Sum3 = target - nums[i];
			for (int j = i + 1;j < nums.size() - 2;++j)
			{
				int Sum2 = Sum3 - nums[j];
				int L = j + 1;
				int R = nums.size() - 1;
				while (L < R)
				{
					if ((nums[L] + nums[R]) < Sum2)
					{	
						++L;
					}
					else if ((nums[L] + nums[R]) > Sum2) 
					{
						--R;
					}
					else
					{
						vector<int> temp;
						temp.push_back(nums[i]);
						temp.push_back(nums[j]);
						temp.push_back(nums[L]);
						temp.push_back(nums[R]);
						result.push_back(temp);
						while (nums[L] == nums[L + 1]) ++L;
						while (nums[R] == nums[R - 1]) --R;
						++L;
					}
				}
				while (j < nums.size() - 3 && nums[j] == nums[j + 1])
				{
					++j;
				}
			}
			while (i < nums.size() - 4 && nums[i] == nums[i + 1])
			{
				++i;
			}
		}
		return result;
    }


