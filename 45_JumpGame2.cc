class Solution {
public:
    int jump(vector<int>& nums) {
        if (nums.empty()) return -1;
		int curReach = 0;
		int maxReach = 0;
		int jump = 0;
		for (int i = 0;i < nums.size();++i)
		{
			if (curReach < i)
			{
				++jump;
				curReach = maxReach;
			}
			maxReach = max(maxReach,nums[i] + i);
		}
		return jump;
    }
};
