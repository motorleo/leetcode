class Solution {
public:
    int trap(vector<int>& height) {
        int currentWater = 0;
		int currentHigh = 0;
		int left = 0;
		int right = height.size() - 1;
		while (left < right)
		{
			int high;
			if (height[left] < height[right])
			{
				high = height[left];
				++left;
			}
			else
			{
				high = height[right];
                --right;
			}
			//count
			if (high <= currentHigh)
			{
				currentWater -= high;
			}
			else
			{
				currentWater -= currentHigh;
				currentWater += (high - currentHigh) * (right - left);
				currentHigh = high;
			}
		}
		return currentWater;
    }
};
