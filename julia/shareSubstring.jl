# link = https://www.hackerrank.com/challenges/two-strings/problem?h_r=profile&isFullScreen=true

function shareSubstring(w1, w2)
    d1 = Dict{Char, Int}()
    for c in w1
        d1[c] = get(d1, c, 0) + 1
    end
    for c in w2
        if get(d1, c, 0) > 0
            println("YES")
            return
        end
    end
    println("NO")
    return nothing
end

n = parse(Int, readline())

for i in 1:n
    word1 = readline()
    word2 = readline()
    shareSubstring(word1, word2)
end
