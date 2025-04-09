class Solution:
    def minimumOperations(self, nums: List[int]) -> int:
        n = len(nums)
        if n == 1:
            return 0

        d = Counter(nums)
        itx = 0
        cnt = 0
        while any(v > 1 for k, v in d.items()):
            if itx == n - 1:
                return cnt
            if itx == n - 2:
                if nums[itx] == nums[itx + 1]:
                    return cnt + 1
                else:
                    return cnt
            d[nums[itx]] -= 1
            d[nums[itx + 1]] -= 1
            d[nums[itx + 2]] -= 1
            #print(d)
            cnt += 1
            itx += 3
        return cnt