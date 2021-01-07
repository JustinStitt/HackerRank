# link = https://www.hackerrank.com/challenges/append-and-delete

function appendAndDelete(s, t, k)
    yes = "Yes"; no = "No"
    n = length(s); m = length(t)
    L = 0 # common length
    for i in 1:min(n, m)
        if s[i] != t[i] break end
        L += 1
    end
    return ( ((n+m) <= k + L*2 && (n+m)%2 == k%2 || (n+m) < k) ? yes : no);
end

s = readline() # initial string
t = readline() # desired string
k = parse(Int, readline()) # exact # of operations to be performed
appendAndDelete(s, t, k) |> println