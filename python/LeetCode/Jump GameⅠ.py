class Solution:
    def canJump(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        pos = 0
        while (pos < len(nums) - 1):
            index = 0
            max_num = 0
            for i in range(1, nums[pos] + 1):
                if pos + i >= len(nums) - 1:
                    return True
                if i + nums[pos + i] > max_num:
                    max_num = i + nums[pos + i]
                    index = i
            if max_num == 0:
                return False
            pos += index
        return True

test = [5,9,3,2,1,0,2,3,3,1,0,0]
so = Solution()
print(so.canJump(test))