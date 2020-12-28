# link = https://www.hackerrank.com/challenges/divisible-sum-pairs

function divisibleSumPairs(n, k, arr)
    count = 0
    for i in 1:n-1, j in i+1:n
        if (arr[i] + arr[j]) % k == 0
            count += 1
        end
    end
    return count
end

n, k = readline() |> split |> x -> parse.(Int, x)
arr = readline() |> split |> x -> parse.(Int, x)
divisibleSumPairs(n, k, arr) |> println
