class Solution:
    def minOperations(self, nums: List[int], k: int) -> int:
        if any(x < k for x in nums):
            return -1
        ret = 0
        dic = Counter(nums)
        return sum(key > k for key,v in dic.items())
#solution 2
class Solution:
    def minOperations(self, nums: List[int], k: int) -> int:
        mn = min(nums)
        if k > mn:
            return -1
        return len(set(nums)) - (k == mn)

#0x3f灵茶山艾府
#我想复杂了
