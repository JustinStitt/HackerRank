import string

alphabet = string.ascii_lowercase

inp = input().rstrip()
n = len(inp)
m = len(alphabet)

dp = [[0 for _ in range(m + 1)] for __ in range(n + 1)]

for r in range(1, n + 1):
    for c in range(1, m + 1):
        # if same
        if inp[r - 1] == alphabet[c - 1]:
            dp[r][c] = 1 + dp[r - 1][c - 1]
        else:
            dp[r][c] = max(dp[r - 1][c], dp[r][c - 1])

print(26 - dp[n][m])
