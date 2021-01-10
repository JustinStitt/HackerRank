# link = https://www.hackerrank.com/challenges/taum-and-bday

function taumBday(b, w, bc, wc, z)::Int
    min(wc, bc + z) * w + min(bc, wc + z) * b
end

t = parse(Int, readline()) # number of test cases
for _ in 1:t
    w, b = readline() |> split |> x->parse.(Int, x) # white, black required
    wc, bc, z = readline() |> split |> x->parse.(Int, x) # white-cost, black-cost, exchange fee
    taumBday(b, w, bc, wc, z) |> println
end