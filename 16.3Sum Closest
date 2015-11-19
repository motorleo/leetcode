
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int len=nums.size();
        if (len==0) return 0;
        if (len==1) return nums[0];
        if (len==2) return nums[0]+nums[1];
        sort(nums.begin(),nums.end());
        int result=nums[0]+nums[1]+nums[2];
        for (int i=0;i<len-2;++i){
            int j=i+1,k=len-1;
            int sum=target-nums[i];
            while (j<k){
                int temp=nums[j]+nums[k];
                if (temp>sum)
                    --k;
                else if (temp<sum)
                    ++j;
                else 
                    return target;
                //update result
                if (abs(temp+nums[i]-target)<abs(result-target))
                    result=temp+nums[i];
            }
        }
        return result;
    }
};