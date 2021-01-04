# link = https://www.hackerrank.com/challenges/30-interfaces
# meant to be interfaces, julia is not an OOP lang so i just derivived the problem

function divisorSum(n)
    csum = 0
    for x in 1:n
        if n % x == 0 csum += x end
    end
    return csum
end

n = parse(Int, readline())
divisorSum(n) |> println