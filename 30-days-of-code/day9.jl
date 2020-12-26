# link =  https://www.hackerrank.com/challenges/30-recursion

function factorial(n)
    if n <= 1 return 1 end
    return n * factorial(n - 1)
end

n = parse(Int, readline())

factorial(n) |> println