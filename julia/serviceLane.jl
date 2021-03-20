# link = https://www.hackerrank.com/challenges/service-lane/problem?isFullScreen=true

function serviceLane(widths, i, j)
    # find minimum in the range i, j
    m = minimum(widths[i+1:j+1])# 1-indexed
    return m
end

n, t = readline() |> split |> x->parse.(Int, x)
widths = readline() |> split |> x->parse.(Int, x)
for _ in 1:t
    i, j = readline() |> split |> x->parse.(Int, x)
    serviceLane(widths, i, j) |> println
end

