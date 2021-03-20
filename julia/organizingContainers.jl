# link = https://www.hackerrank.com/challenges/organizing-containers-of-balls

function organizingContainers(arr)::String
    yes = "Possible"; no = "Impossible"
    # store how much a container can hold
    reserve = Dict{Int, Int}()
    for i in arr
        s = sum(i)
        reserve[s] = get(reserve, s, 0) + 1
    end
    # check count of each column
    for s in sum(arr)
        if get(reserve, s, 0) == 0 return no end
        reserve[s] = get(reserve, s, 0) - 1
    end
    return yes
end

function main()
    # stdin
    q = parse(Int, readline()) # number of queries
    for _ in 1:q
        n = parse(Int, readline()) # number of containers and ball types
        arr = Array{Int, 1}[]
        for __ in 1:n
            row = readline() |> split |> x->parse.(Int, x)
            push!(arr, row)
        end
        organizingContainers(arr) |> println    
    end    
end
main()