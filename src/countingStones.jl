# link = https://www.hackerrank.com/challenges/manasa-and-stones

function countingStones(n, a, b)
    if n <= 2
        return Set{Int}([a,b])
    end

    p = Set{Int}()
    
    o = countingStones(n-1, a, b)
    for e in o
        push!(p, e + a)
        push!(p, e + b)
    end
    
    return p
end

#=
    n = 3, a = 1, b = 2
------------------------------------------------
n=3|            1         |          2
n=2|       2        3     |     3        4
n=1|   3     4    4    5  |  4    5    5    6
=#

function main()
    t = parse(Int, readline()) # number of test cases
    for _ in 1:t
        n = parse(Int, readline()) # num of non-zero stones found
        a = parse(Int, readline()) # one possible diff
        b = parse(Int, readline()) # another possible diff
        o = countingStones(n, a, b) |> collect |> sort
        for e in o print(e, " ") end
        println()
    end
end
main()
