# link = https://www.hackerrank.com/challenges/non-divisible-subset

function nonDivisibleSubset(k::Int, s::Array{Int, 1})::Int
    n = length(s)
    # modulo and frequency
    freq = Dict{Int, Int}()
    for i in 1:n
        s[i] %= k
        freq[s[i]] = get(freq, s[i], 0) + 1
    end
    cmax = 0
    for x in 0:(k/2)
        opp = (k - x) % k
        to_add = max(get(freq, x, 0), get(freq, opp, 0))
        # special cases when x == 0 and x == opp
        if (x == 0   && get(freq, x, 0) > 0) || 
           (x == opp && get(freq, x, 0) > 0)
            to_add = 1    
        end
        cmax += to_add
    end
    return cmax
end

n, k = readline() |> split |> x->parse.(Int, x)
arr = readline() |> split |> x->parse.(Int, x)
nonDivisibleSubset(k, arr) |> println