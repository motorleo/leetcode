class Solution {
public:
    bool canJump(vector<int>& nums) {
        if (nums.empty()) return false;
		int maxReach = nums[0];
		for (int i = 1;i <= maxReach && i < nums.size();++i)
		{
			if (maxReach >= nums.size() - 1)
				break;
			if (nums[i] + i > maxReach)
				maxReach = nums[i] + i;
		}
		if (maxReach >= nums.size() - 1) return true;
		return false;
    }
};
