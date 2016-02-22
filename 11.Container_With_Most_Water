class Solution {
public:
    int maxArea(vector<int>& height) {
        int i=0,j=height.size()-1;
        int maxca=0,capacity=0;
        while (i<j){
            capacity=min(height[i],height[j])*(j-i);
            if (capacity>maxca) maxca=capacity;
            if (height[i]<height[j])
            {
                ++i;
            }
            else
            {
                --j;
            }
        }
        return maxca;
    }
};