n, k, r = [int(x) for x in input().split()]

dna = [int(x) for x in input().split()]
required_quantities = [0 for _ in range(k)]
current = [0 for _ in range(k)]
need = set([])
for _ in range(r):
    base, quant = [int(x) for x in input().split()]
    required_quantities[base] = quant
    need.add(base)
min_length = sum(required_quantities)
# print(required_quantities)

# looks like sliding window
i, j = 0, sum(required_quantities) - 1
smallest = 2**61 - 1337
sat = set()
for x in dna[i : j + 1]:
    if x in need:
        current[x] += 1
        if required_quantities[x] <= current[x]:
            sat.add(current[x])

while i < j < n:
    if len(sat) == len(need):
        smallest = min(smallest, j - i + 1)
        if dna[i] not in need:
            i += 1
            continue
        current[dna[i]] -= 1
        if required_quantities[dna[i]] > current[dna[i]]:
            sat.discard(dna[i])
        i += 1
        continue

    # not satisfied
    j += 1
    if j > n - 1:
        continue
    if dna[j] not in need:
        continue
    current[dna[j]] += 1
    if required_quantities[dna[j]] <= current[dna[j]]:
        sat.add(dna[j])

print(smallest if smallest != 2**61 - 1337 else "impossible")
