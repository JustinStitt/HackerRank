# link = https://www.hackerrank.com/challenges/equality-in-a-array

function equalizeArray(arr)::Int
    freq = Dict{Int, Int}()
    for n in arr
        freq[n] = get(freq, n, 0) + 1
    end
    most = maximum([get(freq, x, 0) for x in arr]) # min-max comprehension
    
    return length(arr) - most
end

n = parse(Int, readline()) # size of arr
arr = readline() |> split |> x->parse.(Int, x)
equalizeArray(arr) |> println