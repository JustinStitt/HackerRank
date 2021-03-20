# link = https://www.hackerrank.com/challenges/picking-numbers
function pickingNumbers(arr)
    sort!(arr)
    longest = 1
    l = 1; r = 2
    n = length(arr)
    while r <= n
        small = minimum(arr[l:r])
        big = maximum(arr[l:r])
        if big - small > 1
            l += 1
            continue
        end
        longest = max(longest, r - l + 1)
        r += 1
    end
    return longest
end

n = parse(Int, readline())
arr = readline() |> split |> x->parse.(Int,x)
pickingNumbers(arr) |> println