# link = https://www.hackerrank.com/challenges/non-divisible-subset

function nonDivisibleSubset(k::Int, s::Array{Int, 1})::Int
    n = length(s)
    # modulo and frequency
    freq = Dict{Int, Int}()
    for i in 1:n
        s[i] %= k
        freq[s[i]] = get(freq, s[i], 0) + 1
    end
    cmax = min(1, get(freq, 0, 0))
    for x in 1:(k/2)
        opp = (k - x) % k
        cmax += max(get(freq, x, 0), get(freq, opp, 0))
    end
    if k & 1 == 0 cmax += min(1, freq[k/2]) end
    return cmax
end

n, k = readline() |> split |> x->parse.(Int, x)
arr = readline() |> split |> x->parse.(Int, x)
nonDivisibleSubset(k, arr) |> println