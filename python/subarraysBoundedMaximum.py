class Solution:
    
    
    def numSubarrayBoundedMax(self, nums: List[int], left: int, right: int) -> int:
        def numSubarrays(n):
            return (n*(n+1)) // 2
        good = [x <= right for x in nums]
        total = curr = 0
        
        # add up triangular numbers
        for x in range(len(good)):
            if not good[curr]: curr = x
            if not good[x] and good[curr]:
                total += numSubarrays(x-curr)
                curr = x
        if good[curr]:
            total += numSubarrays(len(good) - curr)
        
        # now remove triangular numbers below 'low'
        
        bad = [x < left for x in nums]
        curr = 0
        
        for x in range(len(bad)):
            if not bad[curr]: curr = x
            if not bad[x] and bad[curr]:
                total -= numSubarrays(x-curr)
                curr = x
        if bad[curr]:
            total -= numSubarrays(len(bad) - curr)
        return total
