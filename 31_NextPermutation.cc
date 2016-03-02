class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if (nums.size() < 2) return;
		int changeIndex = nums.size() - 2;
		while (changeIndex >= 0 && nums[changeIndex] >= nums[changeIndex + 1])
		{
			--changeIndex;
		}
		if (changeIndex < 0)
		{
			sort(nums.begin(),nums.end());
		}
		else
		{
			int nextIndex = changeIndex + 1;
			int currentNum = nums[changeIndex];
			int nextNum = nums[nextIndex];
			for (int i = nextIndex + 1;i < nums.size();++i)
			{
				if (nums[i] > currentNum && nums[i] < nextNum)
				{
					nextIndex = i;
					nextNum = nums[nextIndex];
				}
			}
			swap(nums[changeIndex],nums[nextIndex]);
			sort(nums.begin() + changeIndex + 1,nums.end());
		}
    }
};
