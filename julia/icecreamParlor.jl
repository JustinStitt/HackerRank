# link = https://www.hackerrank.com/challenges/icecream-parlor/

function icecreamParlor(m, cost)
    freq = Dict{Int, Int}()
    
    for (i, v) in enumerate(cost)
        comp = m - v
        y = get(freq, comp, 0)
        if y > 0
            return [y, i]
        end
        freq[v] = i
    end
    
    return [-1, -1] # superfluous
end

function main()
    t = parse(Int, readline()) # number of test cases
    for _ in 1:t
        m = parse(Int, readline()) # amount of pooled money
        n = parse(Int, readline()) # number of flavors offered
        cost = readline() |> split |> x -> parse.(Int, x)
        out = icecreamParlor(m, cost)
        for e in out print(e, " ") end
        println("")
    end
end
main()
