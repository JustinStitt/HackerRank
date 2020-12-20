# link = https://www.hackerrank.com/challenges/repeated-string/problem?h_r=profile
s = readline()
n = parse(Int, readline())

full = trunc(n / length(s)) |> Int
rem = n % length(s)

whole_a = count(x->x=='a', s) * full
part_a = count(x->x=='a', s[1:rem])

total = whole_a + part_a

println(total)
