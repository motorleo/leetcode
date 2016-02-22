double FindKthNum(int* nums1,int m,int* nums2,int n,int k){
    if (n>m)
        return FindKthNum(nums2,n,nums1,m,k);
    if (n==0)
        return *(nums1+k-1);
    if (k==1)
        return min(*nums1,*nums2);
    
    int k2=min(k/2,n),k1=k-k2;      //k1th num in nums1,k2th num in nums2.
    if (*(nums1+k1-1)<*(nums2+k2-1))
        return FindKthNum(nums1+k1,m-k1,nums2,k2,k-k1);
    else if (*(nums1+k1-1)>*(nums2+k2-1))
        return FindKthNum(nums1,k1,nums2+k2,n-k2,k-k2);
    else 
        return *(nums1+k1-1);
}


class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
        int total=nums1.size()+nums2.size();
        int m=nums1.size(),n=nums2.size();
        int *p1,*p2;
        if (m) p1=&nums1[0];
        if (n) p2=&nums2[0];
        if (total & 0x1)
            return FindKthNum(p1,m,p2,n,total/2+1);
        else
            return (FindKthNum(p1,m,p2,n,total/2)+
            FindKthNum(p1,m,p2,n,total/2+1))/2;
    }
};