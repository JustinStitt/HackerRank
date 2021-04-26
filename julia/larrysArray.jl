# link = https://www.hackerrank.com/challenges/larrys-array/problem

function larrysArray(arr)
    yes = "YES"; no = "NO";
    
    n = length(arr)
    
    s = sum([1 for x in 1:n for y in x+1:n if arr[x] > arr[y]])
    if s & 1 == 0 return yes end
    return no
end

function main()
    t = parse(Int, readline()) # number of test cases

    for _ in 1:t
        n = parse(Int, readline()) # length of array
        arr = readline() |> split |> x->parse.(Int, x)
        larrysArray(arr) |> println
    end
end
main()
