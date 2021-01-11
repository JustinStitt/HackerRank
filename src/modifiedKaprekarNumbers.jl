# link = https://www.hackerrank.com/challenges/kaprekar-numbers

function kaprekarNumbers(l, u)
    satisfied = Int[]
    for n in l:u
        sqr = n * n
        s = join(sqr)
        len = length(s)
        mp = div(len, 2)
        if mp == 0
            csum = parse(Int, s[mp+1:len])
        else
            csum = parse(Int, s[1:mp]) + parse(Int, s[mp+1:len])
        end
        if csum == n push!(satisfied, n) end
    end
    if isempty(satisfied) == true println("INVALID RANGE"); return end
    for x in satisfied print(x, " ") end
end

function main()
    p = parse(Int, readline()) # lower bound
    q = parse(Int, readline()) # upper bound
    kaprekarNumbers(p, q)
end
main()
