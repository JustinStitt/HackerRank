# ksum
def ksum(arr, target, k):
    if k <= 0: return []
    res = []
    for i, n in enumerate(arr):
        if k == 1 and n == target: return [n]
        a = ksum(arr[:i]+arr[i+1:], target-n, k-1)
        if len(a) > 0:
            return [n] + a
    return []


a = [7,8,1,4,5]
result = ksum(a, 20, 3)
print(f'{result=}')

