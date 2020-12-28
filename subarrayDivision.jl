# link = https://www.hackerrank.com/challenges/the-birthday-bar

function divideChocolate(bar, d, m)
    # length = birth month 'm', sum = birth day 'd'
    ways = 0
    n = length(bar)
    for i in 1:(n - m + 1)
        csum = bar[i:i+m-1] |> sum
        if csum == d ways += 1 end
    end
    return ways
end

n = parse(Int, readline()) # number of squares in the chocolate bar
bar = readline() |> split |> x -> parse.(Int, x)
d, m = readline() |> split |> x -> parse.(Int, x)

divideChocolate(bar, d, m) |> println