# link = https://www.hackerrank.com/challenges/30-running-time-and-complexity

function isprime(n)::String
    yes = "Prime"; no = "Not prime"
    n == 1 && return no
    n == 2 && return yes
    if n & 1 == 0 && n > 2 return no end
    l = sqrt(n)
    for d in 3:2:l
        if n % d == 0 return no end
    end
    return yes
end

t = parse(Int, readline()) # number of test cases
for _ in 1:t
    n = parse(Int, readline()) # check if prime
    isprime(n) |> println
end
