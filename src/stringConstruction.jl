# link = https://www.hackerrank.com/challenges/string-construction/problem
function stringConstruction(s)
    # we are just counting the number of unique characters in s
    seen = Dict{Char, Bool}()
    unique = 0
    for c in s
        if !haskey(seen, c)
            seen[c] = true
            unique += 1
        end
    end
    println(unique)
end

n = parse(Int, readline())

for _ in 1:n
    inp = readline()
    stringConstruction(inp)
end
