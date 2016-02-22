class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int index1,index2;
        vector<int> result;
        unordered_map<int,int> hash_map;
        int end=nums.size();
        for (index2=0;index2!=end;++index2){     
            if (!hash_map.count(nums[index2]))         //consider nums[index1]=num[index2].
                hash_map[nums[index2]]=index2;
            int num1=target-nums[index2];
            if (hash_map.count(num1)&&hash_map[num1]<index2){
                index1=hash_map[num1];
                result.push_back(index1+1);
                result.push_back(index2+1);
                return result;
            }
            
        }
    }
};