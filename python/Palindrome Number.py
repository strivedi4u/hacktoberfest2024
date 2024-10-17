'''Given an integer x, return true if x is a palindrome, and false otherwise.'''

class Solution(object):
    def isPalindrome(self, x):
        """
        :type x: int
        :rtype: bool
        """
        num_str=str(x)
        if num_str == num_str[::-1]:
            return True
        else:
            return False    

x=121
sol=Solution()
print(sol.isPalindrome(x))