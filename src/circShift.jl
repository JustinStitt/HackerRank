# link = https://www.hackerrank.com/challenges/circular-array-rotation

function shiftArray!(arr, k)
    n = length(arr)
    for r in 1:k
        pushfirst!(arr, 0) # push a dummy onto front
        arr[1], arr[n + 1] = arr[n + 1], arr[1]
        pop!(arr)
    end
    return arr
end

n, k, q = readline() |> split |> x->parse.(Int, x)
arr = readline() |> split |> x->parse.(Int, x)
#shifted = circshift(arr, k)
shifted = shiftArray!(arr, k)
for _ in 1:q
    idx = parse(Int, readline()) + 1 # to query
    println(shifted[idx])
end