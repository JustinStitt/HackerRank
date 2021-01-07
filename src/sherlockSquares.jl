# link = https://www.hackerrank.com/challenges/sherlock-and-squares

function countSquares(l, r)
    lb = sqrt(l) |> ceil
    rb = sqrt(r) |> floor
    return rb - lb + 1 |> Int
end

function main()
    q = parse(Int, readline()) # number of test cases
    for _ in 1:q
        a, b = readline() |> split |> x->parse.(Int, x)
        countSquares(a, b) |> println
    end
end
main()