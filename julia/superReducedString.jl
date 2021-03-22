# link = https://www.hackerrank.com/challenges/reduced-string/problem

function superReducedString(inp)
    empty = "Empty String"
    s = split(inp, "")
    n = length(s)
    
    x = 2
    while x <= n
        if x <= 1 x += 1 end
        if s[x-1] == s[x]
            deleteat!(s, (x-1, x))
            n -= 2
            x -= 2
        end
        x += 1
    end
    n <= 0 ? empty : join(s)
end

function main()
    inp = readline()
    superReducedString(inp) |> println
end
main()
