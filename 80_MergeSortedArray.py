import copy

class Solution(object):
    def merge(self, nums1, m, nums2, n):
        """
        :type nums1: List[int]
        :type m: int
        :type nums2: List[int]
        :type n: int
        :rtype: void Do not return anything, modify nums1 in-place instead.
        """
        nums1[m:] = nums2[:n]
        nums1.sort()



#c++ style
def merge(nums1, m, nums2, n):
    """
    :type nums1: List[int]
    :type m: int
    :type nums2: List[int]
    :type n: int
    :rtype: void Do not return anything, modify nums1 in-place instead.
    """
    i1 = 0;
    i2 = 0;
    result = list()
    while i1 < m and i2 < n:
        if nums1[i1] < nums2[i2]:
            result.append(nums1[i1])
            i1 += 1
        else:
            result.append(nums2[i2])
            i2 += 1
    for i in range(i1,m):
        result.append(nums1[i])
    for i in range(i2,n):
        result.append(nums2[i])
    print nums1
    print nums2
    print result
    nums1 = copy.copy(result)

l1 = [0]
l2 = [1]
merge(l1,0,l2,1)
print l1
