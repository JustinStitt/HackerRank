p, n = [int(x) for x in input().split()]

parts = set()

for day in range(n):
    piece = input()
    parts.add(piece)
    if len(parts) == p:
        print(day + 1)
        exit(0)
print("paradox avoided")
