class Solution:
    def maxArea(self, h: int, w: int, 
                hcuts: List[int], 
                vcuts: List[int]
    ) -> int:
        hcuts.sort(); vcuts.sort()
        sp = 0
        widths = []
        for x in vcuts:
            widths.append(x-sp)
            sp = x
        widths.append(w-sp) # to the right of the final cut
        sp = 0
        heights = []
        for x in hcuts:
            heights.append(x-sp)
            sp = x
        heights.append(h-sp)
        
        # multiply each width by each height and keep track of running max
        best = max(heights) * max(widths)

        return best % (10**9 + 7)

