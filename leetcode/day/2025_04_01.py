from functools import lru_cache
from typing import List
#solution 1 dfs with two parameters
#out of memory 
class Solution:
    def mostPoints(self, questions: List[List[int]]) -> int:
        n = len(questions)
        curL = [-1] * n
        curM = 0
        @lru_cache(maxsize = None)
        def dfs(itx : int, cur : int):
            nonlocal curM
            if itx >= n:
                curM = max(curM, cur)
                return
            if cur <= curL[itx]:
                return
            curL[itx] = cur
            dfs(itx + questions[itx][1] + 1, cur + questions[itx][0])
            dfs(itx + 1, cur)
            
        dfs(0, 0)
        return curM
#solution 2 dfs with one parameter
#it will do
class Solution:
    def mostPoints(self, questions: List[List[int]]) -> int:
        n = len(questions)
        curM = 0
        @lru_cache(maxsize  = None)
        def dfs(itx : int):
            nonlocal curM
            if itx >= n:
                return 0
            return max(dfs(itx + 1),questions[itx][0] + dfs(itx + questions[itx][1] + 1))
            
        return dfs(0)
#solution 3
#dp
