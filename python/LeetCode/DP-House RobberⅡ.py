class Solution:
    def rob(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        n = len(nums)
        result1 = [i for i in range(0, n - 1)]
        result2 = result1[:]
        if n == 0:
            return 0
        elif n == 1:
            return nums[0]
        elif n == 2:
            return max(nums)
        else:
            result1[0] = nums[0]
            result1[1] = max(nums[0], nums[1])
            for i in range(2, n - 1):
                result1[i] = max(result1[i - 2] + nums[i], result1[i - 1])

            result2[0] = nums[1]
            result2[1] = max(nums[1], nums[2])
            for i in range(3, n):
                result2[i - 1] = max(result2[i - 3] + nums[i], result2[i - 2])

            return max(result2[-1], result1[-1])