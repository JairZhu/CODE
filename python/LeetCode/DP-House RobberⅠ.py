class Solution:
    def rob(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        n = len(nums)
        result = [i for i in range(0, n)]
        if n == 0:
            return 0
        elif n == 1:
            return nums[0]
        elif n == 2:
            return max(nums)
        else:
            result[0] = nums[0]
            result[1] = max(nums[0], nums[1])
            for i in range(2, n):
                result[i] = max(result[i - 2] + nums[i], result[i - 1])
            return result[n - 1]