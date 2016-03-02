
int BinarySearch(vector<int>& nums,int left,int right,int target)
{
	if (left == right)
	{
		if (target > nums[left])
			return left + 1;
		else
			return left;
	}
	if (right - left == 1)
	{
		if (target > nums[right])
			return right + 1;
		else if (target > nums[left])
			return right;
		else
			return left;
	}
	int center = (left + right) >> 1;
	if (nums[center] < target)
		return BinarySearch(nums,center + 1,right,target);
	else if (nums[center] > target)
		return BinarySearch(nums,left,center - 1,target);
	else
		return center;
}

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
		if (nums.empty()) return 0;
		return BinarySearch(nums,0,nums.size() - 1,target);
    }
};
