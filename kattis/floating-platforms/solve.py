n, s, k = [int(x) for x in input().split()]

if n == 1:
    print(k)
    exit(0)

nums = [int(input()) for _ in range(n)]


nums = sorted(nums)

dist = 0

deltas = [abs(nums[i] - nums[i+1]) for i in range(len(nums) - 1)]
for delta in deltas:
    if delta < s:
        print(-1)
        exit(0)

for (i, v) in enumerate(nums[:-1]):
    l = min(k, abs(nums[i] - nums[i+1]))
    l += 0 if nums[i + 1] & 1 else 1
    dist += l

print(dist)
