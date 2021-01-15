# link = https://www.hackerrank.com/challenges/30-bitwise-and

function maximizeAnd(n, k)
    arr = collect(1:n)
    maximum([c < k ? c : 0 for i in 1:(n-1) 
                           for j in (i+1):n 
                           for c = arr[i]&arr[j]])
end

function main()
    t = parse(Int, readline()) # number of test cases
    for _ in 1:t
        n, k = readline() |> split |> x->parse.(Int, x)
        maximizeAnd(n, k) |> println
    end
end
main()
