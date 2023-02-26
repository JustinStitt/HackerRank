starting = 0
t = int(input())


def dfs(value, n, d1, d2, s: set):
    if n == 0:
        return value
    first = dfs(value + d1, n - 1, d1, d2, s)
    second = dfs(value + d2, n - 1, d1, d2, s)
    s.add(first)
    s.add(second)


for _ in range(t):
    n = int(input())
    d1 = int(input())
    d2 = int(input())
    ans = set()
    dfs(0, n - 1, d1, d2, ans)
    as_list = sorted([x for x in ans if x])
    [print(x, end=" ") for x in as_list]
    print()
