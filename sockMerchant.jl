# link = https://www.hackerrank.com/challenges/sock-merchant/problem?h_r=profile
n = readline()

inp = readline()

arr = split(inp) |> x -> parse.(Int, x)

table = Dict{Int,Int}()

for e in arr
    if haskey(table, e)
        table[e] += 1
    else
        get!(table, e, 1)
    end
end

total = 0

for (k, v) in table
    d = v / 2
    global total += trunc(d) |> Int
end

println(total)
