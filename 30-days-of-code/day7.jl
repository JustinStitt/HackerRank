# link = https://www.hackerrank.com/challenges/30-arrays/problem?isFullScreen=true

# goal: print array in reverse order
function reversePrint(arr)
    println(arr[end:-1:begin])
end

n = parse(Int, readline()) # read-in size of array
arr = readline() |> split |> x->parse.(Int, x)
reversePrint(arr)
