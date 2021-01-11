# link = https://www.hackerrank.com/challenges/minimum-distances
#= O(N^2)
function minimumDistances(arr)
    n = length(arr)
    m = minimum([(arr[i] == arr[j] ? 
                    (j-i) : 10^9) for i in 1:(n-1) for j in (i+1):n])
    return (m == 10^9 ? -1 : m)
end
=#
function minimumDistances(arr) # O(N) solution
    n = length(arr)
    dists = Dict{Int, Int}()
    m = 10^9
    for i in 1:n
        j = get(dists, arr[i], 0)
        if j != 0
            m = min(m, i - j)
        end
        dists[arr[i]] = i
    end
    return (m == 10^9 ? -1 : m)
end

function main()
    n = parse(Int, readline()) # size of array 
    arr = readline() |> split |> x->parse.(Int, x)
    minimumDistances(arr) |> println
end
main()
