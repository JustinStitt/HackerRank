# link = https://www.hackerrank.com/challenges/new-year-chaos/problem?h_r=profile
function main()
    t = parse(Int, readline())
    for _ in 1:t
        num_people = parse(Int, readline())
        inp = readline() # ex: "1 2 4 3"
        # convert input to integer array
        arr = split(inp) |> x -> parse.(Int, x)
        println(minimumBribes(num_people, arr))
    end
end

function minimumBribes(n::Int, arr::Array{Int})
    min_swaps = 0
    for (idx, val) in enumerate(arr)
        if val - idx > 2 return "Too chaotic" end
        for x in arr[idx:-1:1]
            if x > val
                min_swaps += 1
            end
         end
    end
    return min_swaps
end

main()
