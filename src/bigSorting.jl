function bigsort!(arr::Array{String, 1})::Array{String, 1}
    # custom sort using 'lt'
    sort!(arr, lt = (x,y) -> (
        (n, m) = (length(x), length(y));
        if n != m
            return n < m
        else
            return x < y
        end
    ))
end

function main()
    arr = ["19","5","6","13","142","111","22","3","14"]
    bigsort!(arr) |> println
end
main()
