# link = https://www.hackerrank.com/challenges/30-review-loop/
function printEvenOdd(s)
    even = s[2:2:length(s)]
    odd = s[1:2:length(s)]
    println(odd, " ", even)
end

n = parse(Int, readline())
for _ in 1:n
    inp = readline()
    printEvenOdd(inp)
end
