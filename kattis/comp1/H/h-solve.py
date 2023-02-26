N = int(input())

bs = ""
# O = 1
# Z = 0

for _ in range(N):
    inp = input()
    bs = bs + ("1" if inp == "O" else "0")

val = int(bs, base=2)
print(val)
