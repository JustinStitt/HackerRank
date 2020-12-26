# link = https://www.hackerrank.com/challenges/fibonacci-modified

function modifiedFibonacci(t1, t2, n)
    # t[i] = t[i - 2] + (t[i - 1])^2
    
    dp = Array{BigInt, 1}(undef, n)
    dp[1] = t1 # first term is given
    dp[2] = t2 # second term is given
    
    for i in 3:n
        dp[i] = dp[i - 2] + (dp[i-1])^2
    end
    return dp[n]
end

inp = readline() |> split # t1, t2, n
t1 = parse(Int, inp[1])
t2 = parse(Int, inp[2])
n = parse(Int, inp[3])
modifiedFibonacci(t1, t2, n) |> println