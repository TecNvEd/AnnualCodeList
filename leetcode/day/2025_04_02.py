class Solution:
    def maximumTripletValue(self, nums: List[int]) -> int:
        n = len(nums)
        d1 = [-1] * n
        d2 = [-1] * n
        for i in range(1,n - 1):
            d1[i] = max(d1[i - 1],nums[i - 1])
        for i in range(n - 2, 0, -1):
            d2[i] = max(d2[i + 1], nums[i + 1])
        return max(max((d1[i] - nums[i]) * d2[i]  for i in range(1,n - 1)),0)


