# link = https://www.hackerrank.com/challenges/staircase/problem

function printStaircase(n::Int)::Nothing
    for (hsh, spce) in zip(1:n, (n-1):-1:0)
        for _ in 1:spce print(" ") end
        for _ in 1:hsh print("#") end
        println("") # new line
    end
end

n = parse(Int, readline())

printStaircase(n)