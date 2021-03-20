# link Google Kickstart Round H archive
function countBoring(l, r)
    boring = 0
    for n in l:r
        arr = digits(n, base = 10) |> reverse
        count = 0
        for (i, v) in enumerate(arr)
            if i & 1 == 1 && v & 1 == 1
                count += 1
            elseif i & 1 == 0 && v & 1 == 0
                count += 1
            end
        end
        if count == length(arr) boring += 1 end
    end
    return boring
end

t = parse(Int, readline()) # number of test cases

for n in 1:t
    l, r = readline() |> split |> x -> parse.(Int, x)
    res = countBoring(l, r)
    println("Case #", n, ": ", res)
end