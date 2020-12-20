# link = https://www.hackerrank.com/challenges/jumping-on-the-clouds/problem?h_r=profile
# greedy approach should work
# always take 2 if available, else take 1

n = parse(Int, readline())
inp = readline()

arr = split(inp) |> x -> parse.(Int, x)

total_jumps = 0
idx = 1
while(idx < length(arr))
    global idx, total_jumps
    # check if we can jump 2 clouds at once
    if idx + 2 <= n && arr[idx + 2] != 1
        idx += 2
    else
        idx += 1
    end
    total_jumps += 1
end

println(total_jumps)
