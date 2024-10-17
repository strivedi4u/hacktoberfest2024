'''Problem statement : Given an array nums containing n distinct numbers in the range [0, n], return the only 
                       number in the range that is missing from the array.'''

class Solution(object):
    def missingNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        nums.sort()
        for i in range(len(nums)):
            if nums[i]!=i:
                return i     
        return len(nums)          
           
nums=[3,0,1]
n=len(nums)
sol=Solution()
print(sol.missingNumber(nums))