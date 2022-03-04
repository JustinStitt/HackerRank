# link = https://www.hackerrank.com/challenges/array-left-rotation
(n, d) = [int(x) for x in input().split(' ')]
nums = [int(x) for x in input().split(' ')]

for _ in range(d):
    first = nums.pop(0)
    nums.append(first)

[print(x, end=' ') for x in nums]
