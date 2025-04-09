class Solution:
    def canPartition(self, nums: List[int]) -> bool:
        n = len(nums)
        if n == 1:
            return False
        s = sum(nums)
        if s % 2 == 1:
            return False
        @cache
        def dfs(itx:int, cur:int) -> bool:
            if itx == n and cur != s / 2 or cur > s:
                return False
            if cur == s / 2:
                return True
            return dfs(itx + 1, cur + nums[itx]) or dfs(itx + 1, cur)
        return dfs(0, 0)

        