# link = https://www.hackerrank.com/challenges/beautiful-triplets

function beautifulTriplets(d, arr)
    n = length(arr)
    count = 0
    for i in 1:n-2
        for j in (i+1):n-1
            if arr[j] - arr[i] != d continue end # optimization step ad-hoc
            for k in (j+1):n
                if arr[k] - arr[j] == d count += 1 end
            end
        end
    end
    return count
end

function main()
    n, d = readline() |> split |> x->parse.(Int, x)
    arr = readline() |> split |> x->parse.(Int, x)
    beautifulTriplets(d, arr) |> println
end
main()
