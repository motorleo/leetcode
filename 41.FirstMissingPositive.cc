class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
		for (int i = 0;i < nums.size();++i)
		{
			while (nums[i] != i + 1 && 
					nums[i] > 0 && nums[i] <= nums.size() &&
					nums[nums[i] - 1] != nums[i])
				swap(nums[nums[i] - 1],nums[i]);
		}
		int resultIndex = 0;
		for (int i = 0;i < nums.size();++i)
		{
			if (nums[i] != i + 1)
			{
				resultIndex = i;
				break;
			}
		}
		if (resultIndex == 0) resultIndex = nums.size();
		return resultIndex + 1;
    }
};
