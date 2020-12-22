# link = https://www.hackerrank.com/challenges/30-loops/problem
function first10(n)
    for i in 1:10
        prod = i * n
        println(n, " x ", i, " = ", prod)
    end
end

n = parse(Int, readline())

first10(n)
