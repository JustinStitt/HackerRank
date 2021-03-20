function hurdleRace(k, height)::Int
    big = maximum(height)
    return (k < big) ? big - k : 0
end

n, k = readline() |> split |> x -> parse.(Int, x)
h = readline() |> split |> x -> parse.(Int, x)
hurdleRace(k, h) |> println