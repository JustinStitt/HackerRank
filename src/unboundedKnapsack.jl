# link = https://www.hackerrank.com/challenges/unbounded-knapsack

function unboundedKnapsack(k, arr)
    dp = fill(0, k)
    for i in 1:k
        for w in arr
            if w > i continue end # superfluous?
            if w == i
                dp[i] = w
                continue
            end
            if dp[i - w] + w > i continue end
            dp[i] = max(dp[i], 
                        dp[i - w] + w)            
        end
    end
    return dp[k]
end


t = parse(Int, readline()) # number of test cases

for _ in 1:t
    nk = readline() |> split |> x->parse.(Int, x)
    n = nk[1] # length of arr
    k = nk[2] # target sum
    arr = readline() |> split |> x -> parse.(Int, x)
    unboundedKnapsack(k, arr) |> println
end

#
#   k seems to be a good bottom-up factor
#   we can build up from 1...k
#   can use previous computations to compute
#
