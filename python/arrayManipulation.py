# link = https://www.hackerrank.com/challenges/crush

(n, m) = [int(x) for x in input().split(' ')]

nums = [0] * (n+2)

for _ in range(m):
    (a, b, k) = [int(x) for x in input().split(' ')]
    nums[a] += k
    nums[b+1] -= k
    
# find largest 
best = nums[0]
running = 0
for n in nums:
    running += n
    best = max(best, running)

print(best)
