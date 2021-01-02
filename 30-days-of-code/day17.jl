# link = https://www.hackerrank.com/challenges/30-more-exceptions

function power(n, p)
    if n < 0 || p < 0
        throw(DomainError((n,p), "n and p should be non-negative"))
    end
    return n ^ p
end

n, p = readline() |> split |> x->parse.(Int, x)

power(n, p) |> println