# link = https://www.hackerrank.com/challenges/permutation-equation

function permutationEquation(p)::Nothing
    n = length(p)
    table = Dict{Int, Int}()
    for (i, v) in enumerate(p)
        table[v] = i
    end
    
    for x in 1:n
        l1 = get(table, x, -1)
        l2 = get(table, l1, -1)
        println(l2)
    end
end

n = parse(Int, readline()) # the number of elements in the sequence
p = readline() |> split |> x->parse.(Int, x)
permutationEquation(p)