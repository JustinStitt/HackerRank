# link = https://www.hackerrank.com/challenges/kangaroo

function kangarooDance(x1, v1, x2, v2)
    if v2 >= v1 return "NO" end
    t = v1 - v2
    x = x2 - x1
    # is x perfectly divisible by t? then they will land on same spot
    x % t == 0 && return "YES"
    return "NO"
end

x1, v1, x2, v2 = readline() |> split |> x -> parse.(Int, x)

kangarooDance(x1, v1, x2, v2) |> println
