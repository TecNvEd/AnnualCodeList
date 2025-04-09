class Solution:
    def subsetXORSum(self, nums: List[int]) -> int:
        ret = 0
        cur = []
        lenN = len(nums)
        def listXORSum(l:List)-> int:
            if not l:
                return 0
            ret1 = l[0]
            if len(l) == 1:
                return ret1
            for x in l[1:]:
                ret1 ^= x
            return ret1
        def dfs(l : list, n : int):
            nonlocal ret
            if n >= lenN:
                ret += listXORSum(cur)
                return
            cur.append(nums[n])
            dfs(l,n + 1)
            cur.pop()

            dfs(l,n + 1)
        dfs(nums, 0)
        return ret
            





