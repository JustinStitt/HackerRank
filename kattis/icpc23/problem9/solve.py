import sys

lat_ratio = float(input())
long_ratio = float(input())

lines = [line.rstrip() for line in sys.stdin.readlines()]


def toSeconds(h, m, s):
    total = s
    total += m * 60
    total += h * 3600
    return total

def dist(x, y, z, a, b, c):
    return ((x - a) ** 2 + (y - b) ** 2 + (z - c) ** 2)**(1/2)

first = True
start = 0
start_alt = 0
start_point = (0, 0, 0)
cumdist = 0.0
for line in lines:
    time, lat, long, alt = line.split()
    lat = float(lat)
    long = float(long)
    # print(time, lat, long, alt)
    converted_lat = lat * lat_ratio
    converted_long = long * long_ratio
    seconds = toSeconds(*[int(x) for x in time.split(':')])
    if first:
        start = seconds
        start_alt = float(alt)
        start_point = (converted_lat, converted_long, float(alt))
        first = False
        continue
    else:
        # print('elapsed: ', seconds - start)
        cumdist += dist(*start_point, converted_lat, converted_long, float(alt))
        start_point = (converted_lat, converted_long, float(alt))
        print(seconds-start, cumdist, float(alt)-start_alt)
