# link = https://www.hackerrank.com/challenges/sherlock-and-valid-string/problem
function isValid(s)
    letters = [0 for _ in 1:26]
    for c in s
        idx = Int(c) - 96
        letters[idx] += 1
    end
    deleteat!(letters, findall(x->x==0,letters)) # remove all 0's
    sort!(letters) # sort by frequency

    differences = 0
    compare = length(letters) > 1 ? letters[2] : letters[1]
    for freq in letters
        if freq != compare
            if freq == 1
                differences += 1
            else
                differences += abs(freq - compare)
            end
        end
        if differences > 1
            println("NO")
            return
        end
    end
    println("YES")

end
 # aabbc
inp = readline()
isValid(inp)
