
int BinarySearch(vector<int>& nums,int left,int right,int target)
{
	if (left > right) return -1;
	int center = (left + right) >> 1;
	if (nums[center] > target)
		return BinarySearch(nums,left,center - 1,target);
	else if (nums[center] < target)
		return BinarySearch(nums,center + 1,right,target);
	else
		return center;
}

int searchPivot(vector<int>& nums,int left,int right)
{
	if (right == left) return left;
	if (right - left == 1)
	{
		if (nums[left] > nums[right])
			return left;
		else 
			return right;
	}
	int center = (left + right) >> 1;
	if (nums[center] < nums[left] && nums[center] < nums[right])
	{
		return searchPivot(nums,left,center - 1);
	}
	else if (nums[center] > nums[left] && nums[center] > nums[right])
	{
		return searchPivot(nums,center,right);
	}
	else if (nums[left] < nums[center] && nums[center] < nums[right])
	{
		return right;
	}
}

class Solution {
public:
    int search(vector<int>& nums, int target) {
        if (nums.empty()) return -1;
		int pivot = searchPivot(nums,0,nums.size() -1);
		if (target < nums[0])
			return BinarySearch(nums,pivot + 1,nums.size() - 1,target);
		else
			return BinarySearch(nums,0,pivot,target);
    }
};
