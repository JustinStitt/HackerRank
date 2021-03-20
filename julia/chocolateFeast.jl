#link = https://www.hackerrank.com/challenges/chocolate-feast/problem?isFullScreen=true

function chocolateFeast(n::Int64, c::Int64, m::Int64)::Int64
    # buy as many bars as we can at first
    wrappers = div(n, c)
    total = wrappers
    while wrappers >= m
        i = div(wrappers, m)
        total += i
        wrappers %= m
        wrappers += i
    end
    total
end

t = parse(Int, readline()) # number of test cases

for _ in 1:t
    n, c, m = readline() |> split |> x->parse.(Int, x)
    chocolateFeast(n, c, m) |> println
end
