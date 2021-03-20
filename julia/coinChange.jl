# link = https://www.hackerrank.com/challenges/coin-change
# DP + Memoization
function getWaysHelper(n, c, dp)
    # base cases
    if n == 0 return 1 end
    if length(c) == 0 return 0 end
    # if we have already computed this, return it
    if dp[n][length(c)] != -1
        return dp[n][length(c)]    
    end
    # otherwise, we need to compute it again
    ways = 0
    div = trunc(n/c[1]) |> Int
    for i in 0:div
        ways += getWaysHelper(n - (i * c[1]), c[2:length(c)], dp)
        # store result in dp
        dp[n][length(c)] = ways
    end
    return ways
end

function getWays(n, c)
    dp = [fill(-1, length(c) + 1) for _ in 1:n]
    return getWaysHelper(n, c, dp)
end

fptr = open(ENV["OUTPUT_PATH"], "w")
first_multiple_input = Array{String}(split(rstrip(readline(stdin))))
n = parse(Int32, first_multiple_input[1])
m = parse(Int32, first_multiple_input[2])
c = map(x -> parse(Int64, x), Array{String}(split(rstrip(readline(stdin)))))
# Print the number of ways of making change for 'n' units using coins having the values given by 'c'
ways = getWays(n, c)
write(fptr, string(ways) * "\n")
close(fptr)