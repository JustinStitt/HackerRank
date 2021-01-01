# link = https://www.hackerrank.com/challenges/beautiful-days-at-the-movies

function beautifulDays(i, j, k)
    num = 0
    for d in i:j
        rev = string(d) |> reverse |> x->parse(Int, x)
        if abs(d - rev) % k == 0 num += 1 end
    end
    return num
end

i, j, k = readline() |> split |> x->parse.(Int, x)
beautifulDays(i, j, k) |> println