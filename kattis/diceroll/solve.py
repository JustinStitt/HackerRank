cases = int(input())

def bfs(grid):
    pass

def solve():
    n = int(input())
    grid = []
    for _ in range(n):
        row = input().split()
        grid.append(row)
    result = bfs(grid)
    print('YES' if result else 'NO')



if __name__ == '__main__':
    for case in range(cases):
        solve()
        exit(0) # !! solve just one (remove before submission)
