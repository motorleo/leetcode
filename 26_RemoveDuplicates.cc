class Solution {
public:
    int removeDuplicates(vector<int>& nums) 
	{
        if (nums.empty()) return 0;
		if (nums.size() == 1) return 1;
		int left = 0;
		int right = 0;
		while (right < nums.size() - 1)
		{
			if (nums[right] == nums[right + 1])
			{
				++right;
			}
			else 
			{
				if (left != right)
					nums[left] = nums[right];
				++left;
				++right;
			}
		}
		nums[left] = nums[right];
		return left + 1;
    }
};


class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) return 0;
        int index = 0;
        for (int i = 1;i < nums.size();++i)
        {
            if (nums[i] != nums[i - 1])
            {
                nums[++index] = nums[i];
            }
        }
        return index + 1;
    }
};
