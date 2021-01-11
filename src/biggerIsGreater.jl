# link = https://www.hackerrank.com/challenges/bigger-is-greater

function biggerIsGreater(s)
    no = "no answer"
    arr = collect(s)
    n = length(arr)
    for i in n:-1:2
        if arr[i] > arr[i-1]
            b = minimum([arr[i]=>i for i in findall(x->x>arr[i-1], arr[i:n]) .+ (i-1)]).second
            arr[i-1], arr[b] = arr[b], arr[i-1]
            arr[i:n] = sort(arr[i:n])
            return arr |> String
        end
    end
    return no
end

function main()
    t = parse(Int, readline()) # num of test cases
    for _ in 1:t
        inp = readline()
        biggerIsGreater(inp) |> println
    end
end
main()