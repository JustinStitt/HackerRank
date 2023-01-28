# https://open.kattis.com/problems/99problems

N = int(input())

up = N
down = N
# count up till ends in 99
while True:
    # ends in 99?
    if str(up)[-2:] == "99":
        break
    up += 1

while True:
    # ends in 99?
    if str(down)[-2:] == "99":
        break
    down -= 1
    if down < 1:
        break

# if down is 0, must pick up
if down == 0:
    print(up)
    exit(0)

# if same pick largest (up)
if abs(N - up) == abs(N - down):
    print(up)
    exit(0)

# otherwise pick closest
if abs(N - up) < abs(N - down):
    print(up)
else:
    print(down)
