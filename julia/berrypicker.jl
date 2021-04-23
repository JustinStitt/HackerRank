#=
= We want the largest slice
= that has at most 2 distinct integers
= return the starting pos i and the ending pos i + k
= where k is the number of berries we can pick to sell
=#
function berrypicker(path::Array{Int, 1}, b::Int)
    # base cases
    length(path) < 1 && return [-1, -1] # no berrys to pick
    length(path) < 2 && return [1, 0] # only take first berry i = 1 k = 1

    i = 1; k = 0; # starting indices
    best = (i = i, k = k)
    while i + k <= length(path)
        if unique(path[i:i+k]) |> length > 2 # more than 2 types of berries
            i += 1
        else # we are using UNDER two types of berries
            if k > best.k
                best = (i = i, k = k)
            end
            k += 1
        end
    end
    return best
end

function main()
    p = [1, 2, 2, 1, 3, 2, 4, 1]; b = 4;
    berrypicker(p, b) |> x -> println("best: ", x)
end
main()